#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T a) {
  return a * a;
}
set<int> adj[33];
bool mark[33];
int dis[33];
void dfs(int v) {
  int _deg = -(1 << 30);
  int vic = -1;
  bool temp = false;
  mark[v] = true;
  for (__typeof((adj[v]).begin()) it = (adj[v]).begin(); it != (adj[v]).end();
       it++)
    if (mark[*it] == false)
      if (temp == false or dis[*it] < _deg) {
        temp = true;
        _deg = dis[*it];
        vic = (*it);
      }
  if (vic != -1) dfs(vic);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(dis, 0, sizeof dis);
  for (register int i = (0); i < (int)(m); (i)++) {
    int a, b;
    cin >> a >> b;
    if (a != b) {
      int _a = (int)(adj[a - 1].size());
      int _b = (int)(adj[b - 1].size());
      adj[a - 1].insert(b - 1);
      adj[b - 1].insert(a - 1);
      if ((int)(adj[a - 1].size()) > _a) dis[a - 1]++;
      if ((int)(adj[b - 1].size()) > _b) dis[b - 1]++;
    }
  }
  for (register int i = (0); i < (int)(n); (i)++) {
    memset(mark, false, sizeof mark);
    dfs(i);
    bool temp = false;
    for (register int j = (0); j < (int)(n); (j)++)
      if (mark[j] == false) {
        temp = true;
        break;
      }
    if (temp == false) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
