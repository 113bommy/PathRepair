#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<int> edges;
signed main() {
  int n;
  cin >> n;
  G.resize(n + 1);
  edges.resize(n + 1, 0);
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    edges[a]++;
    edges[b]++;
  }
  int root = -1;
  vector<int> leaf;
  for (int i = 1; i <= n; i++) {
    if (edges[i] == 1) {
      leaf.push_back(i);
    } else if (edges[i] > 2) {
      if (root == -1) {
        root = i;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  if (root != -1) {
    cout << leaf.size() << endl;
    for (int i = 0; i < leaf.size(); i++) {
      cout << root << ' ' << leaf[i] << endl;
    }
  } else {
    cout << 1 << endl;
    cout << leaf[0] << ' ' << leaf[1] << endl;
  }
}
