#include <bits/stdc++.h>
using namespace std;
const int K = 111;
const int M = 1e6 + 7;
const int Q = 1e9 + 7;
long long p[K];
int c[K];
int a[M];
long long ans, tx, ty, tz;
void calc(long long x, long long y, long long z) {
  long long res;
  res = (long long)x * y + y * z + z * x;
  if (res < ans) {
    ans = res;
    tx = x;
    ty = y;
    tz = z;
  }
}
int main() {
  int T, i, j, k, l, m;
  long long n, x, h, o, r;
  cin >> T;
  while (T--) {
    cin >> k;
    n = 1;
    m = 1;
    a[1] = 1;
    for (i = 1; i <= k; i = i + 1) {
      cin >> p[i] >> c[i];
      for (j = 1; j <= c[i]; j = j + 1) n *= p[i];
      o = m;
      for (l = 1; l <= o; l = l + 1) {
        x = 1;
        for (j = 1; j <= c[i]; j = j + 1) {
          x *= p[i];
          if ((long long)x * a[l] > Q)
            break;
          else
            a[++m] = a[l] * x;
        }
      }
    }
    ans = (long long)n * 2 + 1;
    tx = 1, ty = 1, tz = n;
    sort(a + 1, a + m + 1);
    r = 1;
    for (i = m; i >= 1; i = i - 1) {
      h = a[i];
      if (h > M || (long long)n / h + (long long)2 * sqrt(n) * sqrt(h) > ans)
        continue;
      o = n / h;
      while (r <= m && (long long)a[r] * a[r] <= o) {
        r++;
      }
      r--;
      for (j = r; j >= i; j = j - 1) {
        if (o % a[j] == 0) {
          calc(a[i], a[j], o / a[j]);
          break;
        }
      }
    }
    cout << ans * 2 << ' ' << tx << ' ' << ty << ' ' << tz << endl;
  }
  return 0;
}
