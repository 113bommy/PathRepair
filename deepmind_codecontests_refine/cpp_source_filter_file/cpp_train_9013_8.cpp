#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 3e5 + 5;
vector<int> adj[LIM_N];
vector<int> cols[LIM_N];
int ans[LIM_N];
set<int> avils;
void restor(const int pos, const int pv) {
  for (int i = cols[pos].size(); i; i--) avils.insert(i);
  for (const int x : cols[pos]) {
    if (ans[x]) {
      avils.erase(ans[x]);
    }
  }
  for (const int x : cols[pos]) {
    if (!ans[x]) {
      ans[x] = *avils.begin();
      avils.erase(avils.begin());
    }
  }
}
void dfs(const int pos, const int pv = 0) {
  restor(pos, pv);
  for (const int nxt : adj[pos])
    if (nxt != pv) dfs(nxt, pos);
}
int main() {
  int N, K;
  int A = 0;
  scanf("%d%d", &N, &K);
  for (int i = 1, a; i <= N; i++) {
    scanf("%d", &a);
    cols[i].resize(a);
    A = max(A, a);
    for (int j = 0; j < a; j++) scanf("%d", &cols[i][j]);
  }
  for (int i = 1, a, b; i < N; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  printf("%d\n", A);
  for (int i = 1; i <= K; i++) printf("%d ", ans[i]);
  printf("\n");
}
