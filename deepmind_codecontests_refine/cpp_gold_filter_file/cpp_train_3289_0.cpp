#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int assigned[N];
vector<int> Tree[N];
vector<int> types[N];
void dfs(int u, int p) {
  set<int> s;
  for (int i = 1; i <= types[u].size(); i++) s.insert(i);
  for (auto e : types[u]) {
    if (assigned[e]) {
      s.erase(assigned[e]);
    }
  }
  for (auto e : types[u]) {
    if (!assigned[e]) {
      assert(!s.empty());
      assigned[e] = *s.begin();
      s.erase(s.begin());
    }
  }
  for (auto v : Tree[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int s;
    scanf("%d", &s);
    for (int j = 0; j < s; j++) {
      int t;
      scanf("%d", &t);
      types[i].push_back(t);
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }
  dfs(1, 0);
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    if (!assigned[i])
      assigned[i] = 1;
    else
      ans = max(ans, assigned[i]);
  }
  cout << ans << endl;
  for (int i = 1; i <= m; i++) {
    printf("%d ", assigned[i]);
  }
  cout << endl;
}
