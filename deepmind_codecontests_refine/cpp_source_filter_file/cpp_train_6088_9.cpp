#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 6;
vector<int64_t> g[N];
int64_t cnt = 0;
bool ok[N];
void dfs(int node, int d) {
  ok[node] = true;
  if (d > cnt) cnt = d;
  for (int i : g[node]) {
    if (!ok[i]) dfs(i, d + 1);
  }
}
int main() {
  int64_t n;
  cin >> n;
  map<string, int64_t> m;
  int64_t l = 0;
  int64_t k = 0;
  vector<pair<int64_t, int64_t>> v;
  for (int64_t i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    for (int64_t i = 0; i < a.length(); i++) a[i] = tolower(a[i]);
    for (int64_t i = 0; i < c.length(); i++) c[i] = tolower(c[i]);
    if (m[c] == 0) m[c] = l++;
    if (m[a] == 0) m[a] = l++;
    v.push_back(make_pair(m[a], m[c]));
  }
  k = m["polycarp"];
  for (int64_t i = 0; i < n; i++) {
    g[v[i].second].push_back(v[i].first);
  }
  dfs(k, 1);
  cout << cnt << "\n";
}
