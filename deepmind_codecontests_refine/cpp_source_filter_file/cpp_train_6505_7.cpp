#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long INF = INT_MAX;
const long long MOD = 1e9 + 7;
long long a[N], tmp[N], n, m;
;
inline int32_t isok(long long ans) {
  for (long long i = 0; i < n; i++) tmp[i] = a[i];
  long long j = 0, t = 0;
  for (long long i = 0; i < m; i++) {
    t = j + 1;
    while (t < ans && j < n) {
      if (tmp[j] != 0) {
        long long anss = min(ans - t, tmp[j]);
        t += anss;
        tmp[j] -= anss;
      } else {
        j++;
        t++;
      }
    }
  }
  bool flag = true;
  for (long long i = 0; i < n; i++)
    if (tmp[i] != 0) flag = false;
  return flag;
}
int32_t main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = INF;
  while (r - l > 1) {
    long long md = (l + r) / 2;
    if (isok(md))
      r = md;
    else
      l = md;
  }
  cout << r;
  return 0;
}
