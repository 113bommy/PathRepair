#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int zz = 0; zz < t; zz++) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--;
    b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int t1, t2;
      cin >> t1 >> t2;
      t1--;
      t2--;
      g[t1].push_back(t2);
      g[t2].push_back(t1);
    }
    bool ans = true;
    if (db <= 2 * da) ans = false;
    vector<int> dist1(n), dist2(n), used1(n), used2(n), dist(n), used(n);
    queue<int> q1, q2, q;
    q1.push(0);
    dist1[0] = 0;
    used1[0] = 1;
    int md = 0, mv = 0;
    while (!q1.empty()) {
      int v = q1.front();
      q1.pop();
      for (int u : g[v]) {
        if (!used1[u]) {
          dist1[u] = dist1[v] + 1;
          q1.push(u);
          used1[u] = 1;
          if (dist1[u] > md) {
            md = dist1[u];
            mv = u;
          }
        }
      }
    }
    int td = 0, tv = 0;
    q2.push(mv);
    dist2[mv] = 0;
    used1[mv] = 1;
    while (!q2.empty()) {
      int v = q2.front();
      q2.pop();
      for (int u : g[v]) {
        if (!used2[u]) {
          dist2[u] = dist2[v] + 1;
          q2.push(u);
          used2[u] = 1;
          if (dist2[u] > td) {
            td = dist2[u];
            tv = u;
          }
        }
      }
    }
    q.push(a);
    dist[a] = 0;
    used[a] = 1;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : g[v]) {
        if (!used[u]) {
          dist[u] = dist[v] + 1;
          q.push(u);
          used[u] = 1;
        }
      }
    }
    if (dist[b] <= da) ans = false;
    if (td < 2 * da + 1) ans = false;
    if (ans)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
}
