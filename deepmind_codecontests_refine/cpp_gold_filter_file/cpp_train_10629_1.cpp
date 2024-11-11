#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, k;
struct List {
  int to;
  List *nxt;
  List(int a, List *p) : nxt(p), to(a){};
};
List *G[MAXN];
int cnt[MAXN], dp[MAXN], ans = 1;
void dfs(int u, int fa) {
  vector<int> V;
  dp[u] = 0;
  for (List *p = G[u]; p; p = p->nxt) {
    int v = p->to;
    if (v == fa) continue;
    dfs(v, u);
    dp[u] = max(dp[u], dp[v] + 1);
    V.push_back(dp[v] + 1);
  }
  if (V.size() <= 1) return;
  sort(V.begin(), V.end());
  for (int i = 0; i < V.size() - 1; ++i) {
    if (V[i] + V[i + 1] > k) {
      ans += V.size() - i - 1;
      dp[u] = V[i];
      break;
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u] = new List(v, G[u]);
    G[v] = new List(u, G[v]);
    ++cnt[u], ++cnt[v];
  }
  int st;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 1) {
      st = i;
      break;
    }
  }
  dfs(st, -1);
  cout << ans << endl;
}
