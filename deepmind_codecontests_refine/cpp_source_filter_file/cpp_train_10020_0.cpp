#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e3 + 10;
vector<int> g[MAX];
int qt[MAX];
int dfs(int i, int p = -1) {
  int ret = 1;
  for (int j : g[i])
    if (j != p) ret += dfs(j, i);
  return qt[i] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    x--;
    for (int i = 0; i < n; i++) g[i].clear();
    int deg = 0;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (a == x or b == x) deg++;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (deg <= 1) {
      cout << "Ayush" << '\n';
      continue;
    }
    dfs(x);
    vector<int> v;
    for (int i : g[x]) v.push_back(qt[i]);
    int par = 0;
    for (int i : v) par += (i % 2 == 0);
    if (par % 2 == 1)
      cout << "Ayush" << '\n';
    else
      cout << "Ashish" << '\n';
  }
  exit(0);
}
