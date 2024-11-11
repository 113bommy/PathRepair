#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int mul(int a, int b, int c) { return 1ll * a * b % mod * c % mod; }
int s[maxn][maxn];
int fa[maxn];
void initial(int n, int x) {
  s[0][0] = 0;
  s[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      s[i][j] = add(s[i - 1][j - 1], mul(j, s[i - 1][j]));
    }
  }
  fa[0] = 1;
  for (int i = 1; i <= n; i++) fa[i] = mul(fa[i - 1], x - i + 1);
}
int _pow(int a, int n) {
  int res = 1;
  a %= mod;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
int main(void) {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  initial(min(n, k), n);
  int top = min(n, k);
  int res = 0;
  int p = _pow(m, mod - 2);
  for (int i = 0; i <= top; i++) {
    int update = mul(s[k][i], fa[i], _pow(p, i));
    res = add(res, update);
  }
  printf("%d\n", res);
  return 0;
}
