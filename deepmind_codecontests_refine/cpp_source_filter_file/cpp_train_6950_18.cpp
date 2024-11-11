#include <bits/stdc++.h>
using namespace std;
int s[200500];
vector<int> gr[200500];
int res[200500];
map<int, map<int, int> > w;
char clr[200500];
vector<int> com;
int sum = 0;
int root = 0;
vector<int> tr[200500];
void dfs(int i) {
  clr[i] = 1;
  sum += s[i];
  for (auto u : gr[i]) {
    if (!clr[u]) {
      tr[i].push_back(u);
      dfs(u);
    }
  }
}
void go(int i) {
  for (auto u : tr[i]) {
    go(u);
    if (w[i].count(u)) {
      res[w[i][u]] = s[u];
    } else {
      res[w[u][i]] = s[u];
    }
    s[i] += s[u];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
    w[a][b] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!clr[i]) {
      root = i;
      dfs(i);
      if (sum == 0) {
        go(i);
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) {
    cout << -res[i] << endl;
  }
  return 0;
}
