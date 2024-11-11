#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
vector<int> G[MAXN];
string s;
int id[MAXN], val[MAXN], res[MAXN];
void dfs(int p) {
  if (id[p] == 4) return;
  for (int j = 0; j < G[p].size(); j++) dfs(G[p][j]);
  if (id[p] == 0) val[p] = (val[G[p][0]] & val[G[p][1]]);
  if (id[p] == 1) val[p] = (val[G[p][0]] | val[G[p][1]]);
  if (id[p] == 2) val[p] = (val[G[p][0]] ^ val[G[p][1]]);
  if (id[p] == 3) val[p] = (1 ^ val[G[p][0]]);
}
void work(int p, int v, int sta) {
  if (id[p] == 4) {
    if (sta == 1)
      res[p] = 1 ^ v;
    else if (sta == -1)
      res[p] = 0 ^ v;
    else {
      if (v)
        res[p] = val[p];
      else
        res[p] = val[p] ^ 1;
    }
    return;
  }
  if (sta == 1 || sta == -1) {
    for (int j = 0; j < G[p].size(); j++) work(G[p][j], v, sta);
    return;
  }
  if (id[p] == 0) {
    if (val[G[p][0]] == 0)
      work(G[p][1], v, -1);
    else
      work(G[p][1], v, 0);
    if (val[G[p][1]] == 0)
      work(G[p][0], v, -1);
    else
      work(G[p][0], v, 0);
  }
  if (id[p] == 1) {
    if (val[G[p][0]] == 0)
      work(G[p][1], v, 0);
    else
      work(G[p][1], v, 1);
    if (val[G[p][1]] == 0)
      work(G[p][0], v, 0);
    else
      work(G[p][0], v, 1);
  }
  if (id[p] == 2) {
    if (val[G[p][0]] == 0)
      work(G[p][1], v, 0);
    else
      work(G[p][1], v ^ 1, 0);
    if (val[G[p][1]] == 0)
      work(G[p][0], v, 0);
    else
      work(G[p][0], v ^ 1, 0);
  }
  if (id[p] == 3) {
    work(G[p][0], v ^ 1, 0);
  }
}
int n, u, v, x;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) res[i] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s[0] == 'A') {
      cin >> u >> v;
      G[i].push_back(u);
      G[i].push_back(v);
      id[i] = 0;
    } else if (s[0] == 'O') {
      cin >> u >> v;
      G[i].push_back(u);
      G[i].push_back(v);
      id[i] = 1;
    } else if (s[0] == 'X') {
      cin >> u >> v;
      G[i].push_back(u);
      G[i].push_back(v);
      id[i] = 2;
    } else if (s[0] == 'N') {
      cin >> u;
      G[i].push_back(u);
      id[i] = 3;
    } else {
      id[i] = 4;
      cin >> val[i];
    }
  }
  dfs(1);
  work(1, 0, 0);
  for (int i = 1; i <= n; i++)
    if (id[i] == 4) cout << res[i];
  cout << endl;
  return 0;
}
