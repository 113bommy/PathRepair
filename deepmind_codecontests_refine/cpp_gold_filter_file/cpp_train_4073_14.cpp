#include <bits/stdc++.h>
template <class T>
bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k, l, r, f, u, in, cur;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (int i = 0; i < (int)n; ++i) cin >> a[i];
  l = 0;
  r = n - 1;
  while (l <= r) {
    f = (r + l) / 2;
    u = 0;
    cur = 0;
    in = f;
    while (in < n) {
      if (cur + a[in] > k) {
        ++u;
        cur = 0;
      } else if (u == m)
        break;
      else
        cur += a[in++];
    }
    if (in == n)
      r = f - 1;
    else
      l = f + 1;
  }
  cout << n - l << endl;
  return 0;
}
