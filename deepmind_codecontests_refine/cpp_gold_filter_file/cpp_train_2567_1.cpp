#include <bits/stdc++.h>
using namespace std;
map<long long int, vector<long long int> > g;
long long int s[300005];
void dfs(long long int a, long long int t = 0) {
  s[a] = 1;
  for (auto z : g[a]) {
    if (z != t) {
      dfs(z, a);
      s[a] += s[z];
    }
  }
}
int main() {
  long long int n, x, y;
  cin >> n >> x >> y;
  for (int i = 0; i < n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(x);
  long long int sub_y = s[y];
  memset(s, 0, n);
  dfs(y);
  long long int sub_x = s[x];
  cout << (n * (n - 1)) - (sub_x * sub_y) << endl;
  return 0;
}
