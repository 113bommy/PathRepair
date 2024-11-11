#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N, M;
vector<vector<int> > adj;
bool e = false;
vector<int> col;
int C[2];
void dfs(int u, int c) {
  col[u] = c;
  C[c]++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (col[v] == -1)
      dfs(v, c ^ 1);
    else if (col[v] == c)
      e = true;
  }
}
int main() {
  scanf("%d %d", &N, &M);
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (M == 0) {
    printf("3 %I64d", (long long int)N * (N - 1) * (N - 2) / 6);
    return 0;
  }
  bool c = true;
  int a = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (adj[i].size() >= 2) {
      c = false;
      break;
    }
    if (adj[i].size() == 1) a++;
    if (adj[i].size() == 0) b++;
  }
  if (c) {
    a /= 2;
    printf("2 %I64d", (long long int)a * (2 * a - 2 + b));
    return 0;
  }
  col = vector<int>(N, -1);
  long long int ans = 0;
  for (int i = 0; i < N; i++)
    if (col[i] == -1) {
      C[0] = C[1] = 0;
      dfs(i, 1);
      ans += (long long int)C[0] * (C[0] - 1) / 2;
      ans += (long long int)C[1] * (C[1] - 1) / 2;
    }
  if (e) {
    printf("0 1");
    return 0;
  }
  printf("1 %I64d", ans);
}
