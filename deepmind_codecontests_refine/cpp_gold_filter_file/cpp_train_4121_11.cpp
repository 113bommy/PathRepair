#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
FILE *fin, *fout;
int N;
vector<vector<int> > adj;
vector<pair<int, int> > Ans;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
void dfs(int now, int bf, int dep, int d) {
  vector<int> D;
  for (int i = 0; i < 4; i++) {
    if (i == d) continue;
    D.push_back(i);
  }
  int pos = 0;
  for (int i = 0; i < adj[now].size(); i++) {
    int nxt = adj[now][i];
    if (nxt == bf) continue;
    Ans[nxt] = pair<int, int>(Ans[now].first + dx[D[pos]] * (1 << dep),
                              Ans[now].second + dy[D[pos]] * (1 << dep));
    dfs(nxt, now, dep - 1, 3 - D[pos]);
    pos++;
  }
}
int main() {
  scanf("%d", &N);
  adj.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root = 0;
  int mx = -1;
  for (int i = 0; i < N; i++) {
    if (adj[i].size() > 4) {
      printf("NO");
      return 0;
    }
    if (mx < adj[i].size()) {
      mx = adj[i].size();
      root = i;
    }
  }
  Ans.resize(N);
  Ans[root] = pair<int, int>(0, 0);
  dfs(root, -1, 29, -1);
  printf("YES\n");
  for (int i = 0; i < N; i++) {
    printf("%d %d\n", Ans[i].first, Ans[i].second);
  }
}
