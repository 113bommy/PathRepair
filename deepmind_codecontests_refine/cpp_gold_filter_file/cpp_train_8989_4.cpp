#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int n, m, h, t, c;
vector<pair<int, int> > edge;
vector<int> V[maxn];
inline void out(int u, int v) {
  set<int> fi, se, e;
  for (int i = 0; i < V[u].size(); i++) fi.insert(V[u][i]);
  for (int i = 0; i < V[v].size(); i++) se.insert(V[v][i]);
  for (int i = 0; i < V[u].size(); i++)
    if (binary_search(V[v].begin(), V[v].end(), V[u][i])) {
      fi.erase(V[u][i]);
      se.erase(V[u][i]);
      e.insert(V[u][i]);
    }
  fi.erase(v);
  se.erase(u);
  vector<int> o1, o2;
  if (fi.size() >= h) {
    int i = 1;
    for (set<int>::iterator it = fi.begin(); i <= h; i++, it++)
      o1.push_back(*it);
  } else {
    for (set<int>::iterator it = fi.begin(); it != fi.end(); it++)
      o1.push_back(*it);
    int l = h - fi.size();
    int i = 1;
    vector<int> er;
    for (set<int>::iterator it = e.begin(); i <= l; i++, it++) {
      o1.push_back(*it);
      er.push_back(*it);
    }
    for (i = 0; i < er.size(); i++) e.erase(er[i]);
  }
  if (se.size() >= t) {
    int i = 1;
    for (set<int>::iterator it = se.begin(); i <= t; i++, it++)
      o2.push_back(*it);
  } else {
    for (set<int>::iterator it = se.begin(); it != se.end(); it++)
      o2.push_back(*it);
    int l = t - se.size();
    int i = 1;
    for (set<int>::iterator it = e.begin(); i <= l; i++, it++)
      o2.push_back(*it);
  }
  cout << "YES\n";
  if (c) {
    cout << v << " " << u << "\n";
    for (int i = 0; i < o2.size(); i++) cout << o2[i] << " ";
    cout << "\n";
    for (int i = 0; i < o1.size(); i++) cout << o1[i] << " ";
  } else {
    cout << u << " " << v << "\n";
    for (int i = 0; i < o1.size(); i++) cout << o1[i] << " ";
    cout << "\n";
    for (int i = 0; i < o2.size(); i++) cout << o2[i] << " ";
  }
  exit(0);
}
inline bool newCheck(int u, int v) {
  int bad = 0;
  for (int i = 0; i < V[u].size(); i++)
    if (binary_search(V[v].begin(), V[v].end(), V[u][i])) bad++;
  int a = V[v].size() - 1;
  int b = V[u].size() - 1;
  if (a + b - bad >= t + h) return true;
  return false;
}
inline void check(int u, int v) {
  if (V[u].size() > V[v].size()) swap(u, v);
  int a = V[v].size() - 1;
  int b = V[u].size() - 1;
  if (b < h) return;
  if (a < t) return;
  if (a >= t + h)
    if (b < h)
      return;
    else
      out(u, v);
  if (newCheck(u, v)) out(u, v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> h >> t;
  if (h > t) swap(h, t), c = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
    edge.push_back(pair<int, int>(u, v));
  }
  for (int i = 1; i <= n; i++) sort(V[i].begin(), V[i].end());
  for (int i = 0; i < m; i++) {
    check(edge[i].first, edge[i].second);
  }
  cout << "NO\n";
  return 0;
}
