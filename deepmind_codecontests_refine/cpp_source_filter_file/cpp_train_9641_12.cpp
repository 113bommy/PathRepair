#include <bits/stdc++.h>
using namespace std;
const int N = 251, M = 1e9 + 7;
string s[N];
int dp[N][1 << 15][2][2], n, m;
int calc(int x, int y, int b, int r, int msk) {
  if (y == m) return calc(x + 1, 0, b, 0, msk);
  if (x == n) return 1;
  int& ref = dp[x * m + y][msk][b][r];
  if (ref >= M) ref -= M;
  if (ref + 1) return ref;
  ref = 0;
  if (s[x][y] == 'x') return ref = calc(x, y + 1, b, 0, msk & ~(1 << y)) % M;
  if (r || msk & 1 << y) ref += calc(x, y + 1, b, r, msk);
  if (ref >= M) ref -= M;
  if (!b && !r && !(msk & 1 << y)) ref += calc(x, y + 1, 1, r, msk);
  if (ref >= M) ref -= M;
  ref += calc(x, y + 1, b, 1, msk | 1 << y);
  if (ref >= M) ref -= M;
  return ref;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      scanf("%c", &c);
      if (n > m)
        s[i].push_back(c);
      else
        s[j].push_back(c);
    }
  if (n < m) swap(n, m);
  printf("%d\n", calc(0, 0, 0, 0, 0));
}
