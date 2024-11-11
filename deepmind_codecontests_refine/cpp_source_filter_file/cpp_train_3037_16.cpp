#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long int arr[100001];
long long int st[520000];
void build(long long int in, long long int l, long long int r) {
  if (l == r) {
    st[in] = arr[l];
    return;
  }
  int m = l + (r - l) / 2;
  build(2 * in + 1, l, m);
  build(2 * in + 2, m + 1, r);
  st[in] = st[2 * in + 1] + st[2 * in + 2];
}
long long int query_range(long long int in, long long int l, long long int r,
                          long long int ql, long long int qr) {
  if (ql > qr || qr < l || r < ql) return 0;
  if (ql <= l && qr >= r) return st[in];
  long long int m = l + (r - l) / 2;
  long long int res1 = query_range(2 * in + 1, l, m, ql, qr);
  long long int res2 = query_range(2 * in + 2, m + 1, r, ql, qr);
  return res1 + res2;
}
int main() {
  long long int t, n, k, i, j, m;
  boost();
  cin >> n;
  for (i = 0; i < n; i++) cin >> arr[i];
  build(0, 1, n);
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> m >> k;
    long long int ans = query_range(0, 1, n, m, k);
    cout << (ans / 10) << endl;
  }
  return 0;
}
