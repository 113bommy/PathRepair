#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int des, ch;
};
vector<node> v[105];
int pd[105][105][26];
node t;
int dfs(int x, int y, int c) {
  if (pd[x][y][c] != -1) return pd[x][y][c];
  pd[x][y][c] = 0;
  for (int i = 0; i < v[x].size(); i++) {
    int d = v[x][i].des, nm = v[x][i].ch;
    if (nm >= c) {
      if (!dfs(y, d, nm)) {
        pd[x][y][c] = 1;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  int x, y;
  char z;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    t.des = y, t.ch = z;
    v[x].push_back(t);
  }
  memset(pd, -1, sizeof(pd));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dfs(i, j, 0))
        cout << "A";
      else
        cout << "B";
    }
    cout << endl;
  }
  return 0;
}
