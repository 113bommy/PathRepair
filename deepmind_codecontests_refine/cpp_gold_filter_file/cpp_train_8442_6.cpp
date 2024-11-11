#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void gn(T &x) {
  char ch = getchar(), pl = 0;
  x = 0;
  while (!isdigit(ch)) pl = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= pl ? -1 : 1;
}
const int N = 1e5 + 10;
long long fac[N], finv[N];
long long C(int x, int y) {
  return (y > x || y < 0 || x < 0)
             ? 0ll
             : fac[x] * finv[y] % (1000000007ll) * finv[x - y] % (1000000007ll);
}
int nu[N];
int a, b, c, d, x, y;
long long f(int a, int b, int c, int d) {
  if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
  if (!a && !b && !c && !d) return 1;
  if (b != c + 1 && b != c) return 0;
  int zg, og;
  if (b == c + 1)
    zg = og = b;
  else
    zg = b + 1, og = b;
  return C(a + zg - 1, zg - 1) * C(d + og - 1, og - 1) % (1000000007ll);
}
char l[N], r[N];
long long solve(char str[], int k = 1) {
  int n = strlen(str);
  if (n > a + b + c + d + 1) {
    n = a + b + c + d + 1, k = 1;
    fill(str, str + n, '1');
  } else if (n < a + b + c + d + 1)
    return 0;
  int na, nb, nc, nd;
  long long res = 0;
  na = a, nb = b, nc = c, nd = d;
  for (int i = 1; i < n; i++) {
    if (str[i] == '1') {
      if (str[i - 1] == '0')
        res += f(na - 1, nb, nc, nd);
      else
        res += f(na, nb, nc - 1, nd);
    }
    if (str[i - 1] == '0') {
      if (str[i] == '1')
        nb--;
      else
        na--;
    } else {
      if (str[i] == '1')
        nd--;
      else
        nc--;
    }
  }
  res += f(na, nb, nc, nd) * k;
  return res % (1000000007ll);
}
int main() {
  fac[0] = fac[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < N; i++)
    fac[i] = fac[i - 1] * i % (1000000007ll),
    finv[i] = (-(1000000007ll) / i * finv[(1000000007ll) % i] % (1000000007ll) +
               (1000000007ll)) %
              (1000000007ll);
  for (int i = 2; i < N; i++) finv[i] = finv[i - 1] * finv[i] % (1000000007ll);
  scanf("%s%s", l, r);
  gn(a), gn(b), gn(c), gn(d);
  printf("%lld\n", (solve(r) - solve(l, 0) + (1000000007ll)) % (1000000007ll));
  return 0;
}
