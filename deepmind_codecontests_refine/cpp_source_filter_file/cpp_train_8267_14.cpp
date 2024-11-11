#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 5007;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
vector<pair<int, int> > adj[N];
int kt[N];
vector<pair<pair<int, int>, int> > ans;
int n;
int DFS(int u) {
  vector<int> next;
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j].first;
    int c = adj[u][j].second;
    if (kt[c] == 0) {
      kt[c] = 1;
      int k = DFS(v);
      if (k == 0)
        next.push_back(v);
      else
        ans.push_back(make_pair(make_pair(u, v), k));
    }
  }
  for (int i = 0, tmp = next.size(); i + 1 < tmp; i += 2) {
    ans.push_back(make_pair(make_pair(next[i], u), next[i + 1]));
  }
  if ((next.size() & 1) == 1)
    return next.back();
  else
    return 0;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(make_pair(v, i));
    adj[v].push_back(make_pair(u, i));
  }
  for (int i = 1; i < n + 1; i++) {
    if (DFS(i) > 0) {
      printf("No solution!");
      return 0;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d %d \n", ans[i].first.first, ans[i].first.second,
           ans[i].second);
  }
  return 0;
}
