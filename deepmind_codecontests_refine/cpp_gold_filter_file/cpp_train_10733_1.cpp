#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long> > g(n + 1);
    for (long long i = 0; i < n - 1; i++) {
      long long a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    set<long long> me, you;
    long long k1, k2;
    cin >> k1;
    for (long long i = 0; i < k1; i++) {
      long long x;
      cin >> x;
      me.insert(x);
    }
    cin >> k2;
    for (long long i = 0; i < k2; i++) {
      long long x;
      cin >> x;
      you.insert(x);
    }
    long long R;
    cout << "B " << *you.begin() << '\n';
    cin >> R;
    queue<long long> bfs;
    vector<bool> vis(n + 1);
    bfs.push(R);
    vis[R] = true;
    long long iskomi = 0;
    while (!bfs.empty()) {
      long long node = bfs.front();
      bfs.pop();
      if (me.find(node) != me.end()) {
        iskomi = node;
        break;
      }
      for (auto to : g[node]) {
        if (!vis[to]) {
          bfs.push(to);
          vis[to] = true;
        }
      }
    }
    cout << "A " << iskomi << '\n';
    cout.flush();
    cin >> R;
    if (you.find(R) == you.end()) {
      cout << "C " << -1 << '\n';
    } else {
      cout << "C " << iskomi << '\n';
    }
  }
}
