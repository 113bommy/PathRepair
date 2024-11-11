#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
vector<int> v[100000];
map<pair<int, int>, int> ans;
pair<int, int> road[100000];
;
int dp[20][100000];
int depth[100000];
vector<int> dpos[100000];
int memo[100000];
bool f[100000];
int now = 0;
int lca(int a, int b) {
  if (a == b) return a;
  if (depth[a] > depth[b]) swap(a, b);
  int diff = depth[b] - depth[a];
  for (int i = 0; i < (int)(20); i++)
    if (diff & (1 << i)) {
      b = dp[i][b];
    }
  if (depth[a] != depth[b]) {
    puts("error 1");
  }
  for (int i = 19; i >= 0; i--) {
    if (dp[i][a] != dp[i][b]) {
      a = dp[i][a];
      b = dp[i][b];
    }
  }
  if (a != b) {
    a = dp[0][a];
    b = dp[0][b];
  }
  if (a != b) {
    puts("error 2");
  }
  return a;
}
int main() {
  const int n = getInt();
  for (int i = 0; i < (int)(n - 1); i++) {
    int a = getInt() - 1;
    int b = getInt() - 1;
    v[a].push_back(b);
    v[b].push_back(a);
    road[i].first = min(a, b);
    road[i].second = max(a, b);
  }
  const int root = 0;
  {
    stack<pair<int, int> > st;
    st.push(make_pair(0, -1));
    while (st.size()) {
      pair<int, int> d = st.top();
      st.pop();
      int pos = d.first;
      int p = d.second;
      dp[0][pos] = (p == -1 ? 0 : p);
      depth[pos] = (p == -1 ? 0 : depth[p] + 1);
      dpos[depth[pos]].push_back(pos);
      for (int i = 0; i < (int)(v[pos].size()); i++) {
        int j = v[pos][i];
        if (j != p) st.push(make_pair(j, pos));
      }
    }
  }
  for (int i = 0; i < (int)(19); i++) {
    for (int j = 0; j < (int)(n); j++) {
      dp[i + 1][j] = dp[i][dp[i][j]];
    }
  }
  const int k = getInt();
  for (int i = 0; i < (int)(k); i++) {
    const int a = getInt() - 1;
    const int b = getInt() - 1;
    memo[a]++;
    memo[b]++;
    const int c = lca(a, b);
    memo[c]--;
    memo[c]--;
  }
  for (int d = n - 1; d >= 0; d--) {
    for (int i = 0; i < (int)(dpos[d].size()); i++) {
      int pos = dpos[d][i];
      for (int j = 0; j < (int)(v[pos].size()); j++) {
        int next = v[pos][j];
        if (depth[pos] > depth[next]) {
          ans[make_pair(min(pos, next), max(pos, next))] = memo[pos];
          memo[next] += memo[pos];
        }
      }
    }
  }
  for (int i = 0; i < (int)(n - 1); i++) {
    printf("%d%c", ans[road[i]], i == n - 2 ? '\n' : ' ');
  }
  return 0;
}
