#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j, k, a, b, c, s, aa, bb;
  cin >> n >> m;
  vector<vector<int>> x(n, vector<int>(m));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cin >> x[i][j];
  }
  a = 0;
  b = 1000000000;
  while (a < b) {
    c = (a + b + 1) / 2;
    vector<int> d(1 << m, -1);
    for (i = 0; i < n; i++) {
      s = 0;
      for (j = 0; j < m; j++) {
        if (x[i][j] >= c) s += 1 << j;
      }
      if (d[s] == -1) d[s] = i;
    }
    bool solved = false;
    for (i = 0; i < (1 << m); i++) {
      if (d[i] == -1) continue;
      for (j = i; j < (1 << m); j++) {
        if (d[j] == -1) continue;
        if ((i | j) == ((1 << m) - 1)) {
          solved = true;
          aa = d[i];
          bb = d[j];
          goto outer;
        }
      }
    }
  outer:;
    if (solved)
      a = c;
    else
      b = c - 1;
  }
  c = a;
  vector<int> d(1 << m, -1);
  for (i = 0; i < n; i++) {
    s = 0;
    for (j = 0; j < m; j++) {
      if (x[i][j] >= c) s += 1 << j;
    }
    if (d[s] == -1) d[s] = i;
  }
  bool solved = false;
  for (i = 0; i < (1 << m); i++) {
    if (d[i] == -1) continue;
    for (j = i; j < (1 << m); j++) {
      if (d[j] == -1) continue;
      if ((i | j) == ((1 << m) - 1)) {
        solved = true;
        aa = d[i];
        bb = d[j];
      }
    }
  }
  cout << aa + 1 << " " << bb + 1 << "\n";
  return 0;
}
