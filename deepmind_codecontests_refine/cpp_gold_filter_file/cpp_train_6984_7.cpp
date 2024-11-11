#include <bits/stdc++.h>
const double eps = 1e-10, pi = acos(-1.0);
const int maxS = 1e2 + 10;
const int maxS2 = 5e4 + 10;
const unsigned long long MOD = 1e9 + 7;
using namespace std;
struct point {
  int x, y, z;
};
int n, m, i, j, k, x, y, z, T, ii, t, l, r, pos;
int tot = 0, cnt = 0, ans = 0, sum = 0;
bool chk, chk2[maxS], flag;
string s, s1, s2;
char c[maxS][maxS];
vector<point> res;
void print(int x, int y, int l) {
  int i;
  for (i = x - l; i <= x + l; i++) c[i][y] = '#';
  for (i = y - l; i <= y + l; i++) c[x][i] = '#';
}
bool deal(int x, int y, int l) {
  int i;
  if (x - l < 0 || x + l >= n || y - l < 0 || y + l >= m) return false;
  for (i = x - l; i <= x + l; i++)
    if (c[i][y] == '.') return false;
  for (i = y - l; i <= y + l; i++)
    if (c[x][i] == '.') return false;
  print(x, y, l);
  res.push_back({x, y, l});
  chk = true;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> c[i][j];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (c[i][j] == '*') {
        chk = false;
        for (k = 1; k < min(n, m); k++)
          if (deal(i, j, k)) break;
        if (!chk)
          for (k = 1; k < min(n, m); k++)
            if (deal(i + k, j, k)) break;
        if (!chk)
          for (k = 1; k < min(n, m); k++)
            if (deal(i - k, j, k)) break;
        if (!chk)
          for (k = 1; k < min(n, m); k++)
            if (deal(i, j + k, k)) break;
        if (!chk)
          for (k = 1; k < min(n, m); k++)
            if (deal(i, j - k, k)) break;
      }
  chk = true;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (c[i][j] == '*') chk = false;
  if (!chk)
    cout << -1 << endl;
  else {
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x + 1 << " " << res[i].y + 1 << " " << res[i].z << endl;
  }
  return 0;
}
