#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 100, mo = 1000000000 + 7;
int n, m, f[maxn][maxn], g[maxn][maxn];
char ch[maxn * 5];
void init() {
  f[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    f[i][0] = 1;
    for (int j = 1; j < i; j++) f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mo;
    f[i][i] = f[i][i - 1];
  }
  int n = 2000;
  g[n + 1][n] = 1;
  for (int i = n; i >= 0; i--) {
    g[i][i] = g[i + 1][i];
    for (int j = i - 1; j >= 0; j--) g[i][j] = (g[i + 1][j] + g[i][j + 1]) % mo;
  }
}
int main() {
  init();
  cin >> n >> m;
  scanf("%s", ch);
  int s = 0, s1 = 0;
  for (int i = 0; i < m; i++) {
    if (ch[i] == '(')
      s1--;
    else
      s1++;
    s = max(s, s1);
  }
  int x = n / 2 - (m - s1) / 2, y = n / 2 - (m + s1) / 2;
  if (x < 0 || y < 0)
    cout << "0" << endl;
  else {
    int ans = 0;
    for (int i = 0; i <= y; i++)
      for (int j = i + s; j <= x; j++) {
        long long t1 = f[j][i], t2 = g[2000 - (x - j)][2000 - (y - i)];
        ans = (ans + (t1 * t2) % mo) % mo;
      }
    cout << ans;
  }
  return 0;
}
