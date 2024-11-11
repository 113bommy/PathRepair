#include <bits/stdc++.h>
using namespace std;
struct FastIO {
  inline FastIO& operator>>(int& x) {
    x = 0;
    char f = 0, ch = getchar();
    while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
    while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    return x = (f ? -x : x), *this;
  }
  inline FastIO& operator>>(long long& x) {
    x = 0;
    char f = 0, ch = getchar();
    while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
    while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    return x = (f ? -x : x), *this;
  }
  inline FastIO& operator>>(double& x) {
    x = 0;
    char f = 0, ch = getchar();
    double d = 0.1;
    while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
    while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    if (ch == '.') {
      ch = getchar();
      while (ch <= '9' && ch >= '0')
        x += d * (ch ^ 48), d *= 0.1, ch = getchar();
    }
    return x = (f ? -x : x), *this;
  }
} rin;
long long f[11][65][2055];
int num[100];
long long b, l, r;
long long dfs(int jz, int len, int now, bool zer, bool up) {
  if (len == 0) return now == 0;
  if ((zer == 0) && (up == 0) && (f[jz][len][now] != -1))
    return f[jz][len][now];
  int limt = up ? num[len] : jz - 1;
  long long ret = 0;
  for (int i = 0; i <= limt; ++i) {
    if (zer && i == 0)
      ret += dfs(jz, len - 1, now, 1, up && (i == limt));
    else
      ret += dfs(jz, len - 1, now ^ (1 << i), 0, up && (i == limt));
  }
  if (up == 0 && zer == 0) f[jz][len][now] = ret;
  return ret;
}
long long solve(long long x) {
  int len = 0;
  while (x) {
    num[++len] = x % b;
    x /= b;
  }
  return dfs(b, len, 0, 1, 1);
}
int main() {
  memset(f, -1, sizeof f);
  int q;
  rin >> q;
  while (q--) {
    rin >> b >> l >> r;
    printf("%I64d\n", solve(r) - solve(l - 1));
  }
}
