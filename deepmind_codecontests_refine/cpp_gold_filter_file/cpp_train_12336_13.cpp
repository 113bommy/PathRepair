#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int b[1010][1010];
string s1, s2;
void relax(int i, int j, int k) {
  if (a[i][j] == -1 || k < a[i][j]) a[i][j] = k;
}
int main() {
  for (int i = 0; i < 1010; ++i)
    for (int j = 0; j < 1010; ++j) a[i][j] = -1;
  cin >> s1 >> s2;
  a[0][0] = 0;
  int n = s1.length(), m = s2.length();
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (i != n && j != m)
        if (s1[i] == s2[j])
          relax(i + 1, j + 1, a[i][j]);
        else
          relax(i + 1, j + 1, a[i][j] + 1);
      if (i != n) relax(i + 1, j, a[i][j] + 1);
      if (j != m) relax(i, j + 1, a[i][j] + 1);
    }
  cout << a[n][m] << endl;
  int x = n;
  int y = m;
  stack<pair<int, int> > s;
  s.push(make_pair(x, y));
  while (!(x == 0 && y == 0)) {
    if (x != 0 && y != 0 &&
        ((a[x - 1][y - 1] == a[x][y] && s1[x - 1] == s2[y - 1]) ||
         a[x - 1][y - 1] == a[x][y] - 1)) {
      s.push(make_pair(x - 1, y - 1));
      x -= 1;
      y -= 1;
      continue;
    }
    if (x != 0 && a[x - 1][y] + 1 == a[x][y]) {
      s.push(make_pair(x - 1, y));
      x -= 1;
      continue;
    }
    if (y != 0 && a[x][y - 1] + 1 == a[x][y]) {
      s.push(make_pair(x, y - 1));
      y -= 1;
    }
  }
  pair<int, int> p, p1;
  p = s.top();
  s.pop();
  while (!s.empty()) {
    p1 = s.top();
    s.pop();
    if (p.first + 1 == p1.first && p.second + 1 == p1.second) {
      if (s1[p.first] != s2[p.second]) {
        cout << "REPLACE " << p.second + 1 << " " << s2[p.second] << endl;
      }
    } else {
      if (p.second + 1 == p1.second)
        cout << "INSERT " << p.second + 1 << " " << s2[p.second] << endl;
      else
        cout << "DELETE " << p.second + 1 << endl;
    }
    p = p1;
  }
  return 0;
}
