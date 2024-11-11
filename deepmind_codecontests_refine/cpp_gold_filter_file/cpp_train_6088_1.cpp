#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int nxt = 1;
map<string, int> names;
vector<int> g[maxn + 1];
int d[maxn + 1];
void dfs(int v, int p = 0) {
  d[v] = d[p] + 1;
  for (int x : g[v])
    if (x != p) dfs(x, v);
}
int main() {
  names["polycarp"] = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, rep, b;
    cin >> a >> rep >> b;
    for (int j = 0; j < a.size(); j++) {
      if (isupper(a[j])) a[j] += 32;
    }
    for (int j = 0; j < b.size(); j++) {
      if (isupper(b[j])) b[j] += 32;
    }
    names[a] = ++nxt;
    g[names[b]].push_back(nxt);
  }
  dfs(1);
  cout << *max_element(d, d + maxn + 1) << endl;
  return 0;
}
