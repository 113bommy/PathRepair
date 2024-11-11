#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int mod = 998244353;
int n, m, k;
long long f[70], g[70];
int s[70], ans[70];
int c[70][70], w[70][70];
vector<long long> t;
bool ins(long long x) {
  int i;
  for (((i)) = (((int)(m)) - 1); ((i)) >= (0); ((i))--) {
    if ((x >> i) & 1) {
      if (f[i])
        x ^= f[i];
      else
        return f[i] = x, 1;
    }
  }
  return 0;
}
void rebuild() {
  int i, j;
  for (((i)) = (0); ((i)) <= ((m)-1); ((i))++) {
    for (((j)) = (0); ((j)) <= ((i)-1); ((j))++) {
      if ((f[i] >> j) & 1) {
        f[i] ^= f[j];
      }
    }
  }
}
void dfs(int x, long long cur) {
  if (x == t.size()) {
    s[__builtin_popcountll(cur)]++;
    return;
  }
  dfs(x + 1, cur);
  dfs(x + 1, cur ^ t[x]);
}
int main() {
  int i, j, p, pw = 1;
  read(n);
  read(m);
  c[0][0] = 1;
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    c[i][0] = 1;
    for (((j)) = (1); ((j)) <= ((i)); ((j))++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    long long x;
    read(x);
    if (ins(x))
      k++;
    else
      pw = 2ll * pw % mod;
  }
  rebuild();
  if (k <= 26) {
    for (((i)) = (0); ((i)) <= ((m)-1); ((i))++) {
      if (f[i]) t.push_back(f[i]);
    }
    dfs(0, 0);
    for (((i)) = (0); ((i)) <= ((m + 1) - 1); ((i))++) {
      printf("%d ", 1ll * s[i] * pw % mod);
    }
  } else {
    for (((i)) = (0); ((i)) <= ((m)-1); ((i))++)
      for (((j)) = (0); ((j)) <= ((m)-1); ((j))++) {
        g[j] |= ((f[i] >> j) & 1) << i;
      }
    for (((i)) = (0); ((i)) <= ((m)-1); ((i))++) {
      if (g[i] ^= (1ll << i)) {
        t.push_back(g[i]);
      }
    }
    dfs(0, 0);
    for (((i)) = (0); ((i)) <= ((m + 1) - 1); ((i))++) {
      for (((j)) = (0); ((j)) <= ((m + 1) - 1); ((j))++) {
        for (((p)) = (0); ((p)) <= ((i + 1) - 1); ((p))++) {
          if (p & 1) {
            w[i][j] = (w[i][j] - 1ll * c[j][p] * c[m - j][i - p]) % mod;
            if (w[i][j] < 0) w[i][j] += mod;
          } else {
            w[i][j] = (w[i][j] + 1ll * c[j][p] * c[m - j][i - p]) % mod;
          }
        }
        ans[i] = (ans[i] + 1ll * w[i][j] * s[j]) % mod;
      }
    }
    int t = n - m;
    pw = 1;
    if (t > 0) {
      while (t--) pw = 2ll * pw % mod;
    } else {
      while (t++) pw = 1ll * (mod + 1) / 2 * pw % mod;
    }
    for (((i)) = (0); ((i)) <= ((m + 1) - 1); ((i))++) {
      printf("%d ", 1ll * ans[i] * pw % mod);
    }
  }
  return 0;
}
