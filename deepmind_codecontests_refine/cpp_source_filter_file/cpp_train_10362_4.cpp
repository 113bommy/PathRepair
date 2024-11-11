#include <bits/stdc++.h>
using namespace std;
const int INFint = 2e9;
const long long INF = 2e18;
const long long MOD = 1000000007ll;
set<pair<int, int> > forbidden;
set<int> aval;
vector<int> comp;
int deg;
void dfs(int v, int comps = 1) {
  comp[v] = comps;
  vector<int> go;
  for (auto to : aval) {
    if (forbidden.count(make_pair(v, to))) continue;
    if (v == 0 || to == 0) deg++;
    go.push_back(to);
  }
  for (auto to : go) aval.erase(aval.find(to));
  for (auto to : go) dfs(to, comps);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  comp.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    forbidden.insert(make_pair(a, b));
    forbidden.insert(make_pair(b, a));
  }
  for (int i = 1; i < n; i++) aval.insert(i);
  dfs(0);
  for (int i = 0; i < n; i++) {
    if (!comp[i]) {
      cout << "impossible";
      return 0;
    }
  }
  int maxDeg = deg;
  for (int i = 1; i < n; i++) aval.insert(i);
  int comps = 0;
  comp.assign(n, 0);
  for (int i = 1; i < n; i++) {
    if (!comp[i]) {
      comps++;
      dfs(i, comps);
    }
  }
  if (comps <= maxDeg && k >= comps) {
    cout << "possible";
  } else {
    cout << "impossible";
  }
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  ;
  return 0;
}
