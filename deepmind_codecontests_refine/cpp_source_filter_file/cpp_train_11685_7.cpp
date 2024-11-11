#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> G[200000];
int sn[200000];
int T;
vector<pair<int, int> > path;
void doit(int u, int t) {
  sn[u] = 1;
  int t2 = t - 1;
  path.push_back(make_pair(u, t));
  int d = 0;
  for (int v : G[u])
    if (!sn[v]) d++;
  for (int v : G[u])
    if (!sn[v]) {
      if (t == T) {
        t = t2 - d;
        path.push_back(make_pair(u, t));
      }
      doit(v, t + 1);
      t = t + 1;
      path.push_back(make_pair(u, t));
      d--;
    }
  if (u != 1 && t != t2) {
    assert(t2 < t);
    t = t2;
    path.push_back(make_pair(u, t));
  }
}
int main(void) {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 0; i < N; i++) T = max(T, (int)G[i].size());
  doit(1, 0);
  cout << path.size() << endl;
  for (int i = 0; i < path.size(); i++) {
    cout << path[i].first << " " << path[i].second << endl;
  }
}
