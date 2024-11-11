#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, Z = 10, mod = 1e9 + 7;
char s[N], x[N], y[N];
int d, n, bit[N];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void inc(int& x, int y) { x = add(x, y); }
namespace AC {
int ch[N][10], tot, fail[N];
bool ed[N];
inline void ins(int p) {
  int l = d >> 1, now = 0;
  if (p + l - 1 > n) return;
  for (int i = p; i <= p + l - 1; ++i) {
    int& np = ch[now][s[i] ^ '0'];
    if (!np) np = ++tot;
    now = np;
  }
  ed[now] = 1;
}
inline void gfail() {
  queue<int> q;
  for (int i = 0; i < Z; ++i)
    if (ch[0][i]) fail[ch[0][i]] = 0, q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < Z; ++i)
      if (ch[u][i])
        fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
      else
        ch[u][i] = ch[fail[u]][i];
  }
}
}  // namespace AC
using namespace AC;
int f[N][55][2][2];
inline int solve(char* lim) {
  for (int i = 1; i <= d; ++i) bit[i] = lim[i] ^ '0';
  memset(f, 0, sizeof f);
  f[1][0][0][1] = 1;
  for (int i = 0; i < d; ++i)
    for (int p = 0; p <= tot; ++p)
      for (int ok = 0; ok <= 1; ++ok)
        for (int lm = 0; lm <= 1; ++lm) {
          int& now = f[p][i][ok][lm];
          if (!now) continue;
          int mx = lm ? bit[i + 1] : 9;
          for (int k = 0; k <= mx; ++k) {
            int np = ch[p][k];
            inc(f[np][i + 1][ok | ed[np]][lm & (k == mx)], now);
          }
        }
  int ans = 0;
  for (int p = 0; p <= tot; ++p)
    for (int lm = 0; lm <= 1; ++lm) inc(ans, f[p][d][1][lm]);
  return ans;
}
int main() {
  scanf("%s%s%s", s + 1, x + 1, y + 1);
  d = strlen(x + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) ins(i);
  gfail();
  int t = d;
  while (x[t] == '0') --t;
  --x[t];
  while (t < d) ++t, x[t] = '9';
  printf("%d", dec(solve(y), solve(x)));
  return 0;
}
