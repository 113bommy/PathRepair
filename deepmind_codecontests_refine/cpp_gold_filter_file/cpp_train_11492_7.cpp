#include <bits/stdc++.h>
using namespace std;
vector<int> p[101];
vector<int> l[101];
bool vis[101];
int money = 0;
void dsu(int per) {
  vis[per] = 1;
  for (int i = 0; i < p[per].size(); i++) {
    for (int j = 0; j < l[p[per][i]].size(); j++) {
      if ((vis[l[p[per][i]][j]]) == 0) dsu(l[p[per][i]][j]);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    for (int j = 0; j < r; j++) {
      int x;
      cin >> x;
      p[i].push_back(x);
      l[x].push_back(i);
    }
  }
  vis[1] = 1;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    if (p[i].size() == 0) {
      money++;
      k++;
    } else
      break;
  }
  if (k != n + 1) {
    dsu(k);
    for (int i = k + 1; i <= n; i++) {
      if (!vis[i]) {
        money++;
        dsu(i);
      }
    }
  }
  cout << money << endl;
  return 0;
}
