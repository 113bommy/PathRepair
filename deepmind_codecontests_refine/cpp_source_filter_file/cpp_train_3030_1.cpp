#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> g[n];
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  int b = 0;
  int e = 1;
  unordered_set<int> visited;
  visited.insert(0);
  while (b < e) {
    int u = a[b];
    set<int> c;
    for (auto v : g[u]) {
      if (visited.find(v) == visited.end()) {
        c.insert(v);
      }
    }
    set<int> d;
    for (int i = 0; i < c.size(); ++i) {
      d.insert(a[e] + i);
    }
    if (c != d) {
      cout << "NO\n";
      return 0;
    }
    for (auto i : d) {
      visited.insert(i);
    }
    e += (int)d.size();
    ++b;
  }
  if (e == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
