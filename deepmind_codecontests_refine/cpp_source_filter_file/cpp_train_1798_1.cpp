#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma GCC optimize(3)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const long long INF = 20000000050000;
const int MAXN = 200005;
int N;
std::vector<int> edge[MAXN];
long long H[MAXN], T[MAXN];
long long f[MAXN][2];
long long tmp[MAXN];
std::priority_queue<long long> Qu;
void dfs(int v, int fa) {
  for (int i = 0; i < edge[v].size(); i++)
    if (edge[v][i] != fa) dfs(edge[v][i], v);
  long long ch = edge[v].size() - 1;
  memset(tmp, 0, sizeof(long long) * (ch + 1));
  for (int i = 0; i < edge[v].size(); i++) {
    if (edge[v][i] == fa) continue;
    tmp[ch] += f[edge[v][i]][0];
    Qu.push(f[edge[v][i]][1] - f[edge[v][i]][0]);
  }
  for (long long i = ch - 1, cost = 0; i >= 0; i--) {
    cost += Qu.top();
    Qu.pop();
    tmp[i] = tmp[ch] + cost + (ch - min(i, ch - i)) * T[v];
  }
  tmp[ch] += ch * T[v];
  f[v][0] = f[v][1] = INF;
  for (int i = 0; i <= ch; i++) {
    if (H[v] <= H[fa]) f[v][0] = min(f[v][0], tmp[i] + (i <= ch - i) * T[v]);
    if (H[v] >= H[fa]) f[v][1] = min(f[v][1], tmp[i] + (i >= ch - i) * T[v]);
  }
}
void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%lld", T + i);
  for (int i = 1; i <= N; i++) scanf("%lld", H + i);
  int u, v;
  for (int i = 1; i < N; i++) {
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
}
int main() {
  init();
  for (int i = 1; i <= N; i++)
    if (edge[i].size() == 1) {
      dfs(edge[i][0], i);
      printf("%lld\n", min(f[edge[i][0]][0], f[edge[i][0]][1]) + T[i]);
      break;
    }
  return 0;
}
