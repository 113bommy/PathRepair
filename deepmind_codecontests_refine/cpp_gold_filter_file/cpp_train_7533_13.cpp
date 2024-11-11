#include <bits/stdc++.h>
using namespace std;
string G[102];
int n, m, a, b, c1, flag = true;
void build(int, int);
char fill(int, int, int);
void Print() {
  for (int i = 0; i < n; i++) {
    cout << G[i] << endl;
  }
}
int main() {
  cin >> n >> m >> a >> b >> c1;
  for (int i = 0; i < n; i++) G[i] = string(m, '-');
  if (n % 2 && m % 2) flag = false;
  if (n % 2) {
    for (int i = 0, ff = 0; i < m; i += 2) {
      G[n - 1][i] = G[n - 1][i + 1] = 'a' + ff;
      ff ^= 1;
      a--;
    }
  }
  if (m % 2) {
    for (int i = 0, ff = 0; i < n; i += 2) {
      G[i][m - 1] = G[i + 1][m - 1] = 'a' + ff;
      ff ^= 1;
      b--;
    }
  }
  if (b < 0 || a < 0) flag = false;
  build(0, 0);
  if (!flag)
    cout << "IMPOSSIBLE" << endl;
  else
    Print();
  return 0;
}
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool noprobs(int x, int y, char a);
void build(int r, int c) {
  if (r >= n) return;
  if (c >= m) return build(r + 2, 0);
  if (G[r][c] != '-') return build(r, c + 1);
  if (c1 > 0) {
    G[r][c] = G[r + 1][c] = G[r][c + 1] = G[r + 1][c + 1] = fill(r, c, 0), c1--;
  } else if (b > 1) {
    G[r][c] = G[r + 1][c] = fill(r, c, 1);
    G[r][c + 1] = G[r + 1][c + 1] = fill(r, c + 1, 1);
    b -= 2;
  } else if (a > 1) {
    G[r][c] = G[r][c + 1] = fill(r, c, 2);
    G[r + 1][c] = G[r + 1][c + 1] = fill(r + 1, c, 2);
    a -= 2;
  } else {
    flag = false;
    return;
  }
  return build(r, c + 2);
}
char fill(int r, int c, int type) {
  for (char a = 'a'; a <= 'd'; a++) {
    if (type == 0) {
      if (noprobs(r, c, a) && noprobs(r, c + 1, a) &&
          noprobs(r + 1, c + 1, a) && noprobs(r + 1, c, a))
        return a;
    } else if (type == 1) {
      if (noprobs(r, c, a) && noprobs(r + 1, c, a)) return a;
    } else if (noprobs(r, c, a) && noprobs(r, c + 1, a))
      return a;
  }
}
bool noprobs(int r, int c, char a) {
  for (int i = 0; i < 4; i++) {
    int rr = r + dx[i], cc = c + dy[i];
    if (rr >= 0 && rr < n && cc >= 0 & cc < m) {
      if (G[rr][cc] == a) return false;
    }
  }
  return true;
}
