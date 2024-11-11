#include <bits/stdc++.h>
using namespace std;
vector<int> v[109];
bool visit[109];
void dfs(int i, int p) {
  visit[i] = 1;
  for (auto j : v[i]) {
    if (j != p && !visit[j]) {
      dfs(j, i);
    }
  }
}
int main() {
  int n, i, j, x, y, m;
  scanf("%d%d", &n, &m);
  y = m;
  while (y--) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  bool f = 1;
  dfs(1, 0);
  for (i = 1; i <= n; i++) {
    f = f & visit[i];
  }
  if (n >= 3 && n == m && f == 1) {
    cout << "FHTAGN!" << endl;
    ;
  } else {
    cout << "NO" << endl;
    ;
  }
}
