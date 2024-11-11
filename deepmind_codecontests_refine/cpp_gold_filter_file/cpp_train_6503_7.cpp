#include <bits/stdc++.h>
using namespace std;
const int maxN = 100030;
struct Edge {
  int from, to, w, num;
  Edge(int from = 0, int to = 0, int w = 0, int num = 0)
      : from(from), to(to), w(w), num(num) {}
};
vector<Edge> E[maxN];
Edge edges[maxN];
long long int dp[maxN];
int dfs(int fa, int v) {
  int sum = 0;
  for (int i = E[v].size() - 1; i >= 0; i--) {
    int u = E[v][i].to;
    if (u == fa) continue;
    int d = dfs(v, u);
    sum += d;
    dp[E[v][i].num] = d;
  }
  return sum + 1;
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1, a, b, w; i < N; i++) {
    scanf("%d%d%d", &a, &b, &w);
    edges[i] = Edge(a, b, w, i);
    E[a].push_back(Edge(a, b, w, i));
    E[b].push_back(Edge(b, a, w, i));
  }
  dfs(1, 1);
  for (int i = 1; i < N; i++) dp[i] = dp[i] * (N - dp[i]);
  long long int sum = 0;
  for (int i = 1; i < N; i++) sum += dp[i] * edges[i].w;
  int M;
  scanf("%d", &M);
  double D = 6.0 / N / (N - 1);
  for (int i = 0, a, b; i < M; i++) {
    scanf("%d%d", &a, &b);
    sum -= dp[a] * edges[a].w;
    edges[a].w = b;
    sum += dp[a] * edges[a].w;
    printf("%f\n", (double)sum * D);
  }
}
