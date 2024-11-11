#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, PI = 3.14159265359;
char c[100][100];
map<long long, bool> ma, mb;
multiset<char> ms;
vector<int> v[N], v1[3];
long long n, m, k, ans;
bool mark[100][100], u = false;
void dfs(int x, int y, int xw, int yw) {
  mark[x][y] = true;
  if (c[x + 1][y] == c[x][y]) {
    if (x + 1 != xw || y != yw) {
      if (mark[x + 1][y] == true) {
        u = true;
        return;
      } else
        dfs(x + 1, y, x, y);
    }
  }
  if (c[x - 1][y] == c[x][y]) {
    if (x - 1 != xw || y != yw) {
      if (mark[x - 1][y] == true) {
        u = true;
        return;
      } else
        dfs(x - 1, y, x, y);
    }
  }
  if (c[x][y - 1] == c[x][y]) {
    if (x != xw || y - 1 != yw) {
      if (mark[x][y - 1] == true) {
        u = true;
        return;
      } else
        dfs(x, y - 1, x, y);
    }
  }
  if (c[x][y + 1] == c[x][y]) {
    if (x != xw || y + 1 != yw) {
      if (mark[x][y + 1] == true) {
        u = true;
        return;
      } else
        dfs(x, y + 1, x, y);
    }
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      c[i][j] = s[j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (u == true) {
        cout << "YES";
        return 0;
      }
      for (int k = 0; k <= 100; k++) {
        fill(mark[k], mark[k] + 200, 0);
      }
      dfs(i, j, 0, 0);
    }
  }
  if (u == true) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
