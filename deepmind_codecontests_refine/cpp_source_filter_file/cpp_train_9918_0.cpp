#include <bits/stdc++.h>
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const long long INF = 2000000005;
const long long mod = 998244353;
const int MAXN = 2000000;
int N;
std::vector<int> edge[MAXN];
int f[MAXN];
void dfs(int v, int fa) {
  f[v] = 3 - f[fa];
  for (std::vector<int>::iterator i = edge[v].begin(); i != edge[v].end(); i++)
    if (!f[*i]) dfs(*i, v);
}
void solve0() {
  printf("First\n");
  for (int i = 1; i <= N; i++) printf("%d ", i);
  for (int i = 1; i <= N; i++) printf("%d ", i);
  printf("\n");
  fflush(stdout);
}
void solve() {
  f[0] = 1;
  for (int i = 1; i <= 2 * N; i++)
    if (!f[i]) dfs(i, 0);
  int t = 0;
  for (int i = 1; i <= 2 * N; i++)
    if (f[i] == 1) t += i;
  if (t % (2 * N) == 0) {
    for (int i = 1; i <= 2 * N; i++)
      if (f[i] == 1) printf("%d ", i);
    return;
  }
  for (int i = 1; i <= 2 * N; i++)
    if (f[i] == 2) printf("%d ", i);
}
int main() {
  scanf("%d", &N);
  if (N & 1) {
    printf("Second\n"), fflush(stdout);
    static int tmp[MAXN], t;
    for (int i = 1; i <= 2 * N; i++) {
      scanf("%d", &t);
      if (tmp[t]) {
        edge[i].push_back(tmp[t]);
        edge[tmp[t]].push_back(i);
      } else
        tmp[t] = i;
    }
    for (int i = 1; i <= N; i++)
      edge[i].push_back(i + N), edge[i + N].push_back(i);
    solve();
    fflush(stdout);
  } else
    solve0();
  return 0;
}
