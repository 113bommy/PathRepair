#include <bits/stdc++.h>
using namespace std;
long long kq;
long long n, i, a[100002], f[100002], st[400002];
void update(int id, int l, int r, int u, long long k) {
  if (u < l || u > r) return;
  if (l == r) {
    st[id] = k;
    return;
  }
  int mid = (l + r) >> 1;
  update(id * 2, l, mid, u, k);
  update(id * 2 + 1, mid + 1, r, u, k);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}
long long get(int id, int l, int r, int u, int v) {
  if (u > r || v < l) return round(1e18);
  if (u <= l && r <= v) return st[id];
  int mid = (l + r) >> 1;
  return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i < n; i++) cin >> a[i];
  for (i = n; i >= 1; i--) {
    if (i == n)
      f[i] = 0;
    else
      f[i] = get(1, 1, n, i + 1, a[i]) - i + n - a[i];
    update(1, 1, n, i, f[i] + i);
    kq += f[i];
  }
  cout << kq;
}
