#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007, Inv2 = (Mod + 1) / 2;
const int MN = 2005, MM = 2005;
const long long INF = 1e18;
int N, M, Q, eu[MM], ev[MM], ew[MM];
int to[MM * 2], wgh[MM * 2], tot;
std::vector<int> G[MN];
long long f[MN][MN], Ans[MN];
long long k[MM], b[MM];
int p[MM];
int stk[MN], tp;
int tAns;
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
inline void inc(int &x, int y) { x = x + y < Mod ? x + y : x + y - Mod; }
int main() {
  read(N);
  read(M);
  read(Q);
  for (int i = 1; i <= M; ++i) {
    read(eu[i]);
    read(ev[i]);
    read(ew[i]);
    ++tot, to[tot] = ev[i], wgh[tot] = ew[i];
    G[eu[i]].push_back(tot);
    ++tot, to[tot] = eu[i], wgh[tot] = ew[i];
    G[ev[i]].push_back(tot);
  }
  f[0][1] = 0;
  for (int u = 2; u <= N; ++u) f[0][u] = -INF;
  for (int i = 1; i < N; ++i) {
    Ans[i] = -INF;
    for (int u = 1; u <= N; ++u) {
      f[i][u] = -INF;
      for (int j : G[u]) chkmax(f[i][u], f[i - 1][to[j]] + wgh[j]);
      chkmax(Ans[i], f[i][u]);
    }
  }
  for (int i = 1; i <= M; ++i) {
    long long val = -INF;
    for (int j = 0; j < N; ++j)
      chkmax(val, max(f[j][eu[i]], f[j][ev[i]]) - (long long)j * ew[i]);
    k[i] = ew[i], b[i] = val, p[i] = i;
  }
  sort(p + 1, p + M + 1,
       [](int i, int j) { return k[i] == k[j] ? b[i] < b[j] : k[i] < k[j]; });
  k[0] = 0, b[0] = 0;
  stk[tp = 1] = 0;
  for (int i = 1; i <= M; ++i) {
    while (tp >= 2 &&
           (b[stk[tp - 1]] - b[stk[tp]]) * (k[p[i]] - k[stk[tp]]) >=
               (b[stk[tp]] - b[p[i]]) * (k[stk[tp]] - k[stk[tp - 1]]))
      --tp;
    stk[++tp] = p[i];
  }
  for (int i = 1; i < N; ++i) inc(tAns, Ans[i]);
  for (int i = 2; i <= tp; ++i) {
    long long lb =
        std::max((long long)N,
                 (b[stk[i - 1]] - b[stk[i]]) / (k[stk[i]] - k[stk[i - 1]]) + 1);
    long long rb =
        i == tp ? Q
                : std::min((long long)Q, (b[stk[i]] - b[stk[i + 1]]) /
                                             (k[stk[i + 1]] - k[stk[i]]));
    if (lb > rb) continue;
    tAns = (tAns + (long long)((lb * k[stk[i]] + b[stk[i]]) +
                               (rb * k[stk[i]] + b[stk[i]])) %
                       Mod * (rb - lb + 1) % Mod * Inv2) %
           Mod;
  }
  printf("%d\n", tAns);
  return 0;
}
