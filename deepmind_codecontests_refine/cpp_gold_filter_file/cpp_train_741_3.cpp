#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long pw(long long a, long long b) {
  return (!b ? 1 : (b & 1 ? a * pw(a * a, b / 2) : pw(a * a, b / 2)));
}
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
vector<pair<int, int> > g[MAXN];
int mark[MAXN];
int co[MAXN];
int first = 1;
void DFS(int x, int f) {
  mark[x] = 1;
  co[x] = f;
  for (auto y : g[x]) {
    if (co[y.first] == co[x]) {
      first = 0;
    }
    if (!mark[y.first]) {
      DFS(y.first, -f);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  int nodes[MAXN];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
    nodes[i] = a;
  }
  DFS(0, 1);
  if (!first) return cout << "NO", 0;
  cout << "YES"
       << "\n";
  for (int i = 0; i < m; i++) {
    if (co[nodes[i]] == -1) co[nodes[i]] = 0;
    cout << co[nodes[i]];
  }
  return 0;
}
