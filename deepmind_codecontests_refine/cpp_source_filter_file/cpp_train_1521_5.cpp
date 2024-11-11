#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
struct C {
  double x, y, r;
} base[3050];
double Ans;
int i, j, k;
long long dp[3050][2][2];
int N, mark[3050], fa[3050];
inline double dist(C A, C B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
inline double get_S(C A) { return Pi * A.r * A.r; }
inline bool check_in(C A, C B) { return A.r + B.r >= dist(A, B); }
namespace DP {
struct Edge {
  int next, to;
} E[3050 << 1];
int head[3050], cnt;
inline void Add(int u, int v) {
  E[++cnt].to = v, E[cnt].next = head[u], head[u] = cnt;
  E[++cnt].to = u, E[cnt].next = head[v], head[v] = cnt;
}
void do_dp(int u, int faa) {
  long long f[2][2];
  memset(f, 0, sizeof(f));
  for (int k = head[u]; k; k = E[k].next) {
    if (E[k].to == faa) continue;
    do_dp(E[k].to, u);
    for (int ii = 0; ii <= 1; ++ii)
      for (int jj = 0; jj <= 1; ++jj) f[ii][jj] += dp[E[k].to][ii][jj];
  }
  for (int ii = 0; ii <= 1; ++ii)
    for (int jj = 0; jj <= 1; ++jj)
      dp[u][ii][jj] =
          max(f[ii ^ 1][jj] + (1ll * (ii ? -1 : 1) * base[u].r * base[u].r),
              f[ii][jj ^ 1] + (1ll * (jj ? -1 : 1) * base[u].r * base[u].r));
}
inline bool Comp(C A, C B) { return A.r > B.r; }
void solve1() {
  sort(base + 1, base + N + 1, Comp);
  for (i = 1; i <= N; ++i)
    for (j = i + 1; j <= N; ++j)
      if (check_in(base[i], base[j]))
        if (!fa[j] || base[fa[j]].r > base[i].r) fa[j] = i;
  for (i = 1; i <= N; ++i)
    if (fa[i]) Add(i, fa[i]);
  for (i = 1; i <= N; ++i)
    if (!fa[i]) do_dp(i, 0), Ans += dp[i][0][0];
  printf("%.8lf", Ans * Pi);
}
}  // namespace DP
namespace Greedy {
inline bool Comp(C A, C B) { return A.r > B.r; }
void solve2() {
  sort(base + 1, base + N + 1, Comp);
  for (i = 1; i <= N; ++i)
    for (j = i + 1; j <= N; ++j)
      if (check_in(base[i], base[j])) ++mark[j];
  for (i = 1; i <= N; ++i)
    if (!mark[i] || (mark[i] & 1))
      Ans += get_S(base[i]);
    else
      Ans -= get_S(base[i]);
  printf("%.8lf", Ans);
}
}  // namespace Greedy
int main() {
  cin >> N;
  for (i = 1; i <= N; ++i)
    scanf("%lf%lf%lf", &base[i].x, &base[i].y, &base[i].r);
  if (N <= 500)
    DP ::solve1();
  else
    Greedy ::solve2();
  return 0;
}
