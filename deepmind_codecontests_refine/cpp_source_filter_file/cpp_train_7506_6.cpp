#include <bits/stdc++.h>
using namespace std;
int getint() {
  int ans = 0, f = 1;
  char c = getchar();
  if (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  if (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
const int N = 5e5 + 10, mod = 998244353, inv2 = (mod + 1) / 2;
struct bian {
  int e, n;
};
bian b[N << 1];
int s[N], tot = 0;
void add(int x, int y) {
  tot++;
  b[tot].e = y;
  b[tot].n = s[x];
  s[x] = tot;
}
int f[N];
void ss(int x, int fa) {
  f[x] = 1;
  for (int i = s[x]; i; i = b[i].n) {
    int v = b[i].e;
    if (v == fa) continue;
    ss(v, x);
    f[x] = f[x] * (f[v] + 1ll) % mod * inv2 % mod;
  }
  f[x] = (mod + 1 - f[x]) % mod;
}
int main() {
  int n = getint(), p2 = 1;
  for (int i = 0; i < n - 1; i++) {
    int x = getint(), y = getint();
    add(x, y);
    add(y, x);
    p2 <<= 1;
    p2 >= mod && (p2 -= mod);
  }
  ss(1, 0);
  long long s = 0;
  for (int i = 1; i <= n; i++) s += f[i];
  cout << s % mod * 2 * p2 % mod;
  return 0;
}
