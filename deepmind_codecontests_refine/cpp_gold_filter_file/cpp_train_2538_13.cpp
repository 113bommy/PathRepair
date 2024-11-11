#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 20, S = 1500, mod = 1e9 + 7;
int num[1030], n, m, k;
int a[20][20], f[20][20], v[20];
int dfs(int x, int y) {
  if (y == m + 1) x++, y = 1;
  if (x == n + 1) return 1;
  int s = f[x - 1][y] | f[x][y - 1], calc = -1, res = 0;
  int S = ~s & ((1 << k) - 1);
  if (n + m - x - y + 1 > num[S]) return 0;
  for (int tmp = 0; tmp < k; tmp++)
    if (S & (1 << tmp)) {
      if (!~a[x][y] || a[x][y] == tmp) {
        v[tmp]++;
        f[x][y] = s | (1 << tmp);
        if (v[tmp] == 1) {
          if (!~calc) calc = dfs(x, y + 1);
          res += calc;
        } else
          res += dfs(x, y + 1);
        res = ((res) >= mod ? res - mod : res);
        v[tmp]--;
      }
    }
  return res;
}
int main() {
  for (int i = 1; i < 1024; i++) num[i] = num[i >> 1] + (i & 1);
  n = read(), m = read(), k = read();
  if (n + m - 1 > k) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[i][j] = read() - 1;
      v[a[i][j]]++;
    }
  print(dfs(1, 1)), putchar('\n');
  return 0;
}
