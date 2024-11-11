#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5, MAXD = 5e1 + 5, MAXM = MAXN * MAXD, SIGMA = 10,
          P = 1e9 + 7;
int n, m;
char S[MAXN], X[MAXD], Y[MAXD];
namespace AC {
int ch[SIGMA][MAXM], fail[MAXM], sub[MAXM], nidx;
inline void init() { nidx = 1; }
void getfail() {
  static int Q[MAXM * SIGMA], head, tail;
  Q[head = 1] = tail = 0;
  for (int c = 0; c < SIGMA; ++c) {
    int& v = ch[c][1];
    if (v)
      fail[v] = 1, Q[++tail] = v;
    else
      v = 1;
  }
  while (head <= tail) {
    int u = Q[head++];
    for (int c = 0; c < SIGMA; ++c) {
      int& v = ch[c][u];
      if (v)
        fail[v] = ch[c][fail[u]], Q[++tail] = v;
      else
        v = ch[c][fail[u]];
    }
  }
}
inline void Ins(char* s, int lgt) {
  int u = 1;
  for (int i = 1; i <= lgt; ++i) {
    int c = s[i] - '0';
    if (!ch[c][u]) ch[c][u] = ++nidx;
    u = ch[c][u];
  }
  sub[u] = 1;
}
}  // namespace AC
long long f[2][MAXD][MAXN], g[2][MAXD];
int solve(char* T) {
  using namespace AC;
  for (int i = 1; i <= m; ++i) {
    memset(f[0][i], 0, sizeof f[0][i]);
    memset(f[1][i], 0, sizeof f[1][i]);
  }
  g[0][m + 1] = g[1][m + 1] = 1;
  for (int i = m; i >= 1; --i) {
    g[0][i] = SIGMA * g[0][i + 1] % P;
    g[1][i] = ((T[i] - '0') * g[0][i + 1] + g[1][i + 1]) % P;
  }
  f[1][0][1] = 1;
  for (int i = 1; i <= m; ++i)
    for (int u = 1; u <= nidx; ++u)
      if (!sub[u])
        for (int c = 0; c < SIGMA; ++c) {
          int v = ch[c][u];
          f[0][i][v] = (f[0][i][v] + f[0][i - 1][u]) % P;
          if (c + '0' < T[i]) f[0][i][v] = (f[0][i][v] + f[1][i - 1][u]) % P;
          if (c + '0' == T[i]) f[1][i][v] = (f[1][i][v] + f[1][i - 1][u]) % P;
        }
  int ret = 0;
  for (int i = 1; i <= m; ++i)
    for (int u = 1; u <= nidx; ++u)
      if (sub[u]) {
        long long s1 = f[0][i][u] * g[0][i + 1] % P,
                  s2 = f[1][i][u] * g[1][i + 1] % P;
        ret = (ret + s1 + s2) % P;
      }
  return ret;
}
int main() {
  AC::init();
  scanf("%s%s%s", S + 1, X + 1, Y + 1);
  n = strlen(S + 1), m = strlen(X + 1);
  for (int i = 1; i + m / 2 - 1 <= n; ++i) AC::Ins(S + i - 1, m / 2);
  AC::getfail();
  int x = m;
  while (x > 0 && X[x] == '0') X[x--] = '9';
  --X[x];
  printf("%d\n", (solve(Y) - solve(X) + P) % P);
  return 0;
}
