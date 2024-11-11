#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int arr[MAX], X[MAX], Y[MAX], C[MAX];
int n, m;
pair<int, int> con[MAX];
vector<vector<int> > weight(MAX);
int par[MAX];
void init() {
  for (int i = 0; i < MAX; ++i) par[i] = i;
}
int root(int node) {
  if (par[node] == node) return node;
  return (par[node] = root(par[node]));
}
void Union(int x, int y) {
  int a = root(x);
  int b = root(y);
  if (a == b) return;
  par[b] = a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> X[i] >> Y[i] >> C[i];
    con[i].first = con[i].second = -1;
    weight[C[i]].push_back(i);
  }
  init();
  for (int i = 1; i < MAX; ++i) {
    for (auto &j : weight[i]) {
      if (root(X[j]) != root(Y[j]))
        con[j].first = root(X[j]), con[j].second = root(Y[j]);
    }
    for (auto &j : weight[i]) Union(X[j], Y[j]);
  }
  int q;
  cin >> q;
  while (q--) {
    int sz;
    cin >> sz;
    bool flag = true;
    vector<pair<int, int> > vp;
    for (int i = 0; i < sz; ++i) {
      int x;
      cin >> x;
      x--;
      if (con[x].first == -1 || con[x].second == -1) {
        flag = false;
        continue;
      }
      vp.push_back({con[x].first, con[x].second});
    }
    if (flag == false) {
      cout << "NO\n";
      continue;
    }
    for (auto &i : vp) par[i.first] = i.first, par[i.second] = i.second;
    for (auto &i : vp) {
      if (root(i.first) == root(i.second))
        flag = false;
      else
        Union(i.first, i.second);
    }
    if (flag == true)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
