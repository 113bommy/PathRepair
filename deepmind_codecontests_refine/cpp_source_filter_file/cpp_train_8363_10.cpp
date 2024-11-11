#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int A[N], f[3], n, s;
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", A + i), ++f[A[i] - 3];
  int res(~0u >> 2), ri, rk, rj;
  for (int i = s / n; i >= 0; --i) {
    int tw = s - i * f[0], si = i * f[0];
    if (tw % gcd(f[1], f[2])) continue;
    for (int j = min(tw / (f[1] + f[2]), (si + res) / f[1]);
         j >= i && j >= (si - res) / f[1]; --j) {
      int sj = j * f[1], k = (tw - sj) / f[2], sk = k * f[2];
      int w1 = sk - sj, w2 = si - sj;
      if (w1 > res || w2 > res || w1 + w2 > res) break;
      if (si + sj + sk != s) continue;
      int cr = abs(w1) + abs(w2);
      if (cr < res) res = cr, ri = i, rj = j, rk = k;
    }
  }
  if (res == (~0u >> 1))
    puts("-1");
  else
    printf("%d %d %d\n", ri, rj, rk);
}
