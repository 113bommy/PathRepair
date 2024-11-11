#include <bits/stdc++.h>
using namespace std;
int n, s, l, j;
int a[1000010], tx[1000010], tn[1000010], f[1000010];
void init(int id, int l, int r) {
  if (l == r) {
    tx[id] = a[l];
    tn[id] = a[l];
    return;
  }
  int mid = (r + l) >> 1;
  init(id * 2, l, mid);
  init(id * 2 + 1, mid + 1, r);
  tx[id] = max(tx[id * 2], tx[id * 2 + 1]);
  tn[id] = min(tn[id * 2], tn[id * 2 + 1]);
}
int getn(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 1e9;
  if (l >= u && r <= v) return tn[id];
  int mid = (r + l) >> 1;
  return min(getn(id * 2, l, mid, u, v), getn(id * 2 + 1, mid + 1, r, u, v));
}
int getx(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 0;
  if (l >= u && r <= v) return tx[id];
  int mid = (r + l) >> 1;
  return max(getx(id * 2, l, mid, u, v), getx(id * 2 + 1, mid + 1, r, u, v));
}
bool check(int l, int r) {
  int mx = getx(1, 1, n, l, r);
  int mn = getn(1, 1, n, l, r);
  return (mx - mn) <= s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s >> l;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) f[i] = 1e9;
  init(1, 1, n);
  for (int i = 1; i <= n; i++) {
    while (i - j >= l && !check(j + 1, i) || f[j] == 1e9) j++;
    if (i - j >= l) f[i] = min(f[i], f[j] + 1);
  }
  if (f[n] == 1e9) f[n] = -1;
  cout << f[n];
  return 0;
}
