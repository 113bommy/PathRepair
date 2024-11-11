#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, res;
char q[60][60];
int me(int i, int j) {
  int z, x, w = 0;
  if ((i + a) > n || (j + b) > m) return n * m;
  for (z = i; z < i + a; z++) {
    for (x = j; x < j + b; x++) {
      if (q[z][x] == '1') w++;
    }
  }
  return w;
}
int mer(int i, int j) {
  int z, x, w = 0;
  if ((i + b) > n || (j + a) > m) return n * m;
  for (z = i; z < i + b; z++) {
    for (x = j; x < j + a; x++) {
      if (q[z][x] == '1') w++;
    }
  }
  return w;
}
int min(int r, int y) {
  if (r <= y) return r;
  return y;
}
int main() {
  int i, j, u;
  cin >> n >> m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> q[i][j];
  cin >> a >> b;
  res = n * m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      u = min(me(i, j), mer(i, j));
      res = min(u, res);
    }
  }
  cout << res;
  return 0;
}
