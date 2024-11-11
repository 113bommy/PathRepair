#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long linf = 2e18;
const long long mod = 998244353;
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el << " ";
  }
  return s;
}
int n, a[200007], ile[200007], tree[200007], v, u, odw[200007];
vector<int> vec[200007];
void dfs(int x) {
  odw[x] = 1;
  if (a[x] == 1)
    tree[x] = 1;
  else
    tree[x] = -1;
  for (int i = 0; i < vec[x].size(); i++) {
    if (odw[vec[x][i]] == 0) {
      dfs(vec[x][i]);
      if (tree[vec[x][i]] > 0) tree[x] += tree[vec[x][i]];
    }
  }
}
void dfs2(int x, int pop) {
  odw[x] = 1;
  int pom = 0;
  if (tree[x] > 0)
    pom = tree[pop] - tree[x];
  else
    pom = tree[pop];
  if (pom > 0) tree[x] += pom;
  for (int i = 0; i < vec[x].size(); i++) {
    if (odw[vec[x][i]] == 0) {
      dfs2(vec[x][i], x);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> v >> u;
    vec[v].push_back(u);
    vec[u].push_back(v);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) odw[i] = 0;
  tree[0] = -1000000007;
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) cout << tree[i];
  return 0;
}
