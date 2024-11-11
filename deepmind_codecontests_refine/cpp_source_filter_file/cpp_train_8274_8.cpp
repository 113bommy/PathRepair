#include <bits/stdc++.h>
using namespace std;
const int N = 233;
int a[N][N], fa[N * N];
int id[N][N], reid[N * N];
int n, m, mo;
char s[N][N];
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
int Det(int n) {
  int ans = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = (a[i][j] + mo) % mo;
  for (int i = 1; i <= n; i++) {
    if (!a[i][i]) {
      for (int j = i + 1; j <= n; j++)
        if (a[j][i]) {
          for (int k = i + 1; k <= n; k++) swap(a[i][k], a[j][k]);
          ans = mo - ans;
        }
    }
    if (!a[i][i]) return 0;
    ans = 1ll * ans * a[i][i] % mo;
    for (int j = i + 1; j <= n + 1; j++) {
      int t = 1ll * a[j][i] * power(a[i][i], mo - 2) % mo;
      for (int k = i; k <= n + 1; k++)
        a[j][k] = (a[j][k] + mo - 1ll * t * a[i][k] % mo) % mo;
    }
  }
  return ans;
}
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
int uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) return fa[x] = y, 1;
  return 0;
}
void adde(int x, int y) {
  x = reid[get(x)];
  y = reid[get(y)];
  a[x][x]++;
  a[y][y]++;
  a[x][y]--;
  a[y][x]--;
}
int solve(int fl) {
  int num = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if ((i + j + fl) % 2 == 0) id[i][j] = ++num;
  for (int i = 1; i <= num; i++) fa[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char wzp = ((i + j + fl) % 2 ? '/' : '\\');
      if (s[i][j] != wzp) continue;
      if (wzp == '/') {
        if (!uni(id[i - 1][j], id[i][j - 1])) return 0;
      } else {
        if (!uni(id[i - 1][j - 1], id[i][j])) return 0;
      }
    }
  int c = 0;
  for (int i = 1; i <= num; i++)
    if (get(i) == i) reid[i] = ++c;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*')
        if ((i + j + fl) % 2 == 1)
          adde(id[i - 1][j], id[i][j - 1]);
        else
          adde(id[i - 1][j - 1], id[i][j]);
  return Det(c - 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &mo);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  printf("%d", (solve(0) + solve(1)) % mo);
}
