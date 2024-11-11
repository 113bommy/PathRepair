#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
void hey() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<int> g[100000];
bool mxmi = 0;
int ans;
int was[N];
void dfs(int v, int d) {
  if (d % 2 && g[v].size() == 1) {
    mxmi = 1;
  }
  int kol = 0;
  was[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (g[g[v][i]].size() == 1) {
      kol++;
    }
    if (!was[g[v][i]]) {
      dfs(g[v][i], d + 1);
    }
  }
  ans -= max(kol - 1, 0);
}
int main() {
  hey();
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ans = n - 1;
  int start = -1;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      start = i;
      break;
    }
  }
  dfs(start, 0);
  cout << (mxmi ? 3 : 1) << " " << ans;
}
