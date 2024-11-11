#include <bits/stdc++.h>
using namespace std;
unordered_set<int> g[101];
int n;
void check(int x) {
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    unordered_set<int> tmp = g[x];
    int t = tmp.size();
    for (auto j = g[i].begin(); j != g[i].end(); j++) {
      tmp.insert(*j);
    }
    if (tmp.size() != t) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  cin >> n;
  int m;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      g[i].insert(x);
    }
  }
  for (int i = 1; i <= n; i++) check(i);
  return 0;
}
