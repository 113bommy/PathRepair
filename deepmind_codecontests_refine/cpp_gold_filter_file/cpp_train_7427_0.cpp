#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t, _x, _y, best;
pair<int, int> ans, now;
int L[2010][2010], R[2010][2010];
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && (ch != '-'); ch = getchar())
    ;
  if (ch == '-')
    a = 0, __t = -1;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a *= __t;
}
void updata(pair<int, int> now) {
  int D = abs(now.first - _x) + abs(now.second - _y);
  if (D < best) best = D, ans = now;
  if (D == best) ans = min(ans, now);
}
void check(int x, int y) {
  now.first = x;
  now.second = L[x][y];
  if (now.second != 0) updata(now);
  now.second = R[x][y];
  if (now.second != n + 1) updata(now);
}
int main() {
  read(m), read(n), read(o);
  for (int i = (0); i <= (m + 1); i++)
    for (int j = (0); j <= (n + 1); j++) L[i][j] = R[i][j] = j;
  for (; o--;) {
    read(_x), read(_y);
    best = m + n + 2;
    ans.first = 1000000000;
    for (int D = 0; D <= best; D++) {
      if (_x - D > 0) check(_x - D, _y);
      if (_x + D <= m) check(_x + D, _y);
    }
    printf("%d %d\n", ans.first, ans.second);
    int x = ans.first, y = ans.second;
    L[x][y] = L[x][y - 1];
    R[x][y] = R[x][y + 1];
    for (int i = y + 1; i <= n && L[x][i] != i; i++) L[x][i] = L[x][y - 1];
    for (int i = y - 1; i && R[x][i] != i; i--) R[x][i] = R[x][y + 1];
  }
}
