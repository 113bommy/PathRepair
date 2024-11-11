#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> edges[1000 + 5];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    int k1;
    cin >> k1;
    vector<int> subtree1(k1);
    set<int> st1;
    for (int i = 0; i < k1; i++) {
      cin >> subtree1[i];
      st1.insert(subtree1[i]);
    }
    int k2;
    cin >> k2;
    vector<int> subtree2(k2);
    set<int> st2;
    for (int i = 0; i < k2; i++) {
      cin >> subtree2[i];
      st2.insert(subtree2[i]);
    }
    cout << "B " << subtree2[0] << "\n";
    int start;
    cin >> start;
    queue<int> q;
    q.push(start);
    vector<int> visited(n + 1, 0);
    int nearest;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited[u] = true;
      if (st1.find(u) != st1.end()) {
        nearest = u;
        break;
      }
      for (auto v : edges[u]) {
        if (!visited[v]) q.push(v);
      }
    }
    cout << "A " << nearest << "\n";
    int res;
    cin >> res;
    if (st2.find(res) != st2.end())
      cout << "C " << res << "\n";
    else
      cout << "C " << -1 << "\n";
    cout.flush();
  }
}
