#include <bits/stdc++.h>
using namespace std;
int a, s, d, f, g, h, j, k, l, i, n, m;
string x[2], z[2];
char c;
int dfs(int i1, int i2, int tri) {
  if (x[0] == z[0] && x[1] == z[1]) {
    return 1;
  }
  if (tri < 0) return 0;
  int ret = 0;
  if (i1 < 1) {
    c = x[i1][i2];
    x[i1][i2] = x[i1 + 1][i2];
    x[i1 + 1][i2] = c;
    ret = dfs(i1 + 1, i2, tri - 1);
    c = x[i1][i2];
    x[i1][i2] = x[i1 + 1][i2];
    x[i1 + 1][i2] = c;
  }
  if (i1 > 0) {
    c = x[i1][i2];
    x[i1][i2] = x[i1 - 1][i2];
    x[i1 - 1][i2] = c;
    ret |= dfs(i1 - 1, i2, tri - 1);
    c = x[i1][i2];
    x[i1][i2] = x[i1 - 1][i2];
    x[i1 - 1][i2] = c;
  }
  if (i2 < 1) {
    c = x[i1][i2];
    x[i1][i2] = x[i1][i2 + 1];
    x[i1][i2 + 1] = c;
    ret |= dfs(i1, i2 + 1, tri - 1);
    c = x[i1][i2];
    x[i1][i2] = x[i1][i2 + 1];
    x[i1][i2 + 1] = c;
  }
  if (i2 > 0) {
    c = x[i1][i2];
    x[i1][i2] = x[i1][i2 - 1];
    x[i1][i2 - 1] = c;
    ret |= dfs(i1, i2 - 1, tri - 1);
    c = x[i1][i2];
    x[i1][i2] = x[i1][i2 - 1];
    x[i1][i2 - 1] = c;
  } else
    return 0 | ret;
}
int main() {
  cin >> x[0] >> x[1] >> z[0] >> z[1];
  for (i = 0; i < 2; i++) {
    for (a = 0; a < 2; a++) {
      if (x[i][a] == 'X') {
        l = i;
        j = a;
      }
    }
  }
  if (dfs(l, j, 4) != 0)
    cout << "YES";
  else
    cout << "NO";
}
