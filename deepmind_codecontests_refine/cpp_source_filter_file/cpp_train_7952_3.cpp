#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (n == 1)
    cout << "1\n";
  else {
    vector<int> cuts(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      cuts[u]++;
      cuts[v]++;
    }
    int f;
    for (int i = 2; i <= n; i++) {
      if (cuts[i] == 0) {
        f = i;
        break;
      }
    }
    vector<pair<int, int> > p;
    p.emplace_back(make_pair(1, f));
    for (int i = 2; i <= n; i++) {
      if (i == f) continue;
      p.emplace_back(make_pair(i, f));
    }
    cout << (int)p.size() << "\n";
    for (auto it : p) cout << it.first << " " << it.second << "\n";
  }
}
