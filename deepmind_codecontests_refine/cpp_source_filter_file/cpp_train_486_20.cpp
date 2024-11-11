#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  int numloops = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (u == v) {
      if (n > 1) {
        cout << "NO" << endl;
        exit(0);
      } else {
        numloops++;
        if (numloops > 1) {
          cout << "NO" << endl;
          exit(0);
        }
      }
    }
    g[u].push_back(v);
    g[v].push_back(u);
    if (int(g[u].size()) > 2 or int(g[v].size()) > 2) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  if (n == 1) {
    cout << "YES" << endl;
    if (numloops == 1) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl << "1 1" << endl;
    }
    exit(0);
  }
  vector<int> visto(n, 0);
  bool alguno = false;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  for (int u = 0; u < n; u++) {
    if (not visto[u] and int(g[u].size()) < 2) {
      alguno = true;
      visto[u] = 1;
      if (int(g[u].size()) == 0) {
        q.push(pair<int, int>(u, u));
      } else if (int(g[u].size()) == 1) {
        int antv = u;
        int v = g[u][0];
        visto[v] = 1;
        while (int(g[v].size()) == 2) {
          int nextv = g[v][0];
          if (nextv == antv) nextv = g[v][1];
          antv = v;
          v = nextv;
          visto[v] = 1;
        }
        q.push(pair<int, int>(u, v));
      }
    }
  }
  if (not alguno) {
    cout << "YES" << endl << 0 << endl;
    exit(0);
  }
  for (int u = 0; u < n; u++) {
    if (not visto[u]) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  vector<pair<int, int> > sol;
  while (int(q.size()) > 2) {
    pair<int, int> p1 = q.top();
    q.pop();
    pair<int, int> p2 = q.top();
    q.pop();
    sol.push_back(pair<int, int>(p1.first, p2.first));
    pair<int, int> p(p1.second, p2.second);
    if (p.first > p.second) swap(p.first, p.second);
    q.push(p);
  }
  pair<int, int> p = q.top();
  sol.push_back(pair<int, int>(p.first, p.second));
  cout << "YES" << endl;
  cout << int(sol.size()) << endl;
  for (int i = 0; i < int(sol.size()); i++) {
    if (sol[i].first > sol[i].second) swap(sol[i].first, sol[i].second);
    cout << sol[i].first + 1 << " " << sol[i].second + 1 << endl;
  }
}
