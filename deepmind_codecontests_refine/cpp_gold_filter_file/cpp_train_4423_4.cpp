#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 1010;
int n;
bool e[N][N];
pair<int, int> rotate(int a, int b, bool inv) {
  int x = 0, y = 0;
  for (int j = 1; j < n; j++)
    if (e[a][j] && e[b][j]) {
      y = j;
      break;
    }
  e[a][b] = e[b][a] = 0;
  e[x][y] = e[y][x] = 1;
  if (inv)
    return pair<int, int>(x, y);
  else
    return pair<int, int>(a, b);
}
vector<pair<int, int> > solve(bool inv) {
  vector<pair<int, int> > res;
  int x, y;
  memset(e, 0, sizeof(e));
  for (int i = 0; i < n; i++) e[i][(i + 1) % n] = e[(i + 1) % n][i] = 1;
  for (int i = 0; i < n - 3; i++)
    x = read() - 1, y = read() - 1, e[x][y] = e[y][x] = 1;
  for (int i = 1; i < n; i++) {
    if (e[0][i]) continue;
    int k = i + 1;
    for (;; k++)
      if (e[0][k]) break;
    res.push_back(rotate(i - 1, k, inv));
    i--;
  }
  if (inv) reverse(res.begin(), res.end());
  return res;
}
int main() {
  n = read();
  vector<pair<int, int> > ans1 = solve(0);
  vector<pair<int, int> > ans2 = solve(1);
  printf("%d\n", ans1.size() + ans2.size());
  for (pair<int, int> d : ans1) printf("%d %d\n", d.first + 1, d.second + 1);
  for (pair<int, int> d : ans2) printf("%d %d\n", d.first + 1, d.second + 1);
  return 0;
}
