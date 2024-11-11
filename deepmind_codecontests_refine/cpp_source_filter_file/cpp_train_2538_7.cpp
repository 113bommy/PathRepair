#include <bits/stdc++.h>
using namespace std;
const double g = 9.8;
const double pi = acos(-1.0);
const int N = 1e3 + 10;
const int M = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const int BLOCK = N;
unsigned int Table[N];
int n, m, k;
int tu[N][N];
int num[N], num1[1030];
int s[N][N];
void add(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
int dfs(int x, int y) {
  if (y == m + 1) x++, y = 1;
  if (x == n + 1) return 1;
  int res = -1;
  int ans = 0;
  int las = s[x - 1][y] | s[x][y - 1];
  int T = ((~las) & ((1 << k) - 1));
  if (n + m - x - y + 1 > num1[T]) return 0;
  for (int i = 0; i < k; ++i)
    if ((T >> i) & 1) {
      if (tu[x][y] == 0 || tu[x][y] == i + 1) {
        num[i + 1]++;
        s[x][y] = las | (1 << i);
        if (num[i + 1] == 1) {
          if (res == -1) res = dfs(x, y + 1);
          add(ans, res);
        } else {
          add(ans, dfs(x, y + 1));
        }
        num[i + 1]--;
      }
    }
  return ans;
}
int main() {
  for (int i = 1; i <= 1024; ++i) num1[i] = num1[i >> 1] + (i & 1);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &tu[i][j]);
      num[tu[i][j]]++;
    }
  }
  if ((n + m - 1) > k) return 0 * puts("0");
  printf("%d\n", dfs(1, 1));
}
