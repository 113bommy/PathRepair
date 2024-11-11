#include <bits/stdc++.h>
using namespace std;
int MAXBIT = 30;
long long sum[1000010];
int l[1000010], r[1000010], q[1000010];
int a[1000010], t[4 * 1000010];
void build(int v, int l, int r) {
  if (l + 1 == r) {
    t[v] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build((v * 2), l, mid);
  build((v * 2) + 1, mid, r);
  t[v] = t[(v * 2)] & t[(v * 2) + 1];
}
int query(int v, int l, int r, int L, int R) {
  if (l == L && r == R) return t[v];
  int mid = (L + R) >> 1;
  int ans = (1ll << MAXBIT) - 1;
  if (l < mid) ans &= query(v * 2, l, min(r, mid), L, mid);
  if (mid < r) ans &= query(v * 2 + 1, max(l, mid), r, mid, R);
  return ans;
}
int main() {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    l[i]--;
  }
  for (int bit = 0; bit <= MAXBIT; bit++) {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < m; i++) {
      if ((q[i] >> bit) & 1) {
        sum[l[i]]++;
        sum[r[i]]--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) sum[i] += sum[i - 1];
      if (sum[i] > 0) a[i] |= (1 << bit);
    }
  }
  build(1, 0, n);
  for (int i = 0; i < m; i++) {
    if (query(1, l[i], r[i], 0, n) != q[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
