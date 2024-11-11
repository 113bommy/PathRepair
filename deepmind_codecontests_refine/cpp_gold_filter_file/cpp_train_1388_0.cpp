#include <bits/stdc++.h>
const int N = 10005, a[5][5] = {{2, 29, 31, 53, 97},
                                {3, 23, 37, 59, 89},
                                {5, 19, 41, 61, 83},
                                {7, 17, 43, 67, 79},
                                {11, 13, 47, 71, 73}};
int f[17][5][N * 27], g[5][N * 480], q[55][55], n, m, d, x, y, ans;
char s[N];
long long v[N], c;
int dfs(int *f, int x, int y, int w, int p) {
  if (y >= n) return 1;
  int &t = f[x];
  if (t >= 0) return t;
  while (w >= 0 && (q[d][w] < 0 || x / q[d + 1][w] % (d + 1) != d)) w--;
  if (w < 0) return t = v[y] % p;
  t = 1, y += d * q[d][w];
  for (int i = 0; i < d; i++)
    x -= q[d + 1][w], y -= q[d][w], t = 1LL * t * dfs(f, x, y, w - 1, p) % p;
  return t;
}
void work(int *f, const int a[], int &ans) {
  int p = 1, res;
  for (int i = 0; i < 5; i++) p *= a[i];
  res = (c + dfs(f, x, y, 15, p)) % p;
  for (int i = 0; i < 5; i++)
    if (res % a[i] == 0 && a[i] < ans) ans = a[i];
}
int get(char x) {
  if (x == '?')
    return d;
  else if (x <= '9')
    return x - '0';
  else
    return x - 'A' + 10;
}
void change(int m, char *s, int &x, int &y) {
  while (m--) {
    int z = get(*s++);
    if (z < d) {
      if (q[d][m] < 0 && z) {
        y = n;
        return;
      }
      y += z * q[d][m], x += z * q[d + 1][m];
    } else if (q[d][m] >= 0 && q[d][m] < n)
      x += z * q[d + 1][m];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &v[i]);
  scanf("%d", &m);
  memset(f, -1, sizeof(f));
  memset(g, -1, sizeof(g));
  for (int i = 1; i <= 17; i++) {
    q[i][0] = 1;
    for (int j = 1; j <= 36; j++) {
      q[i][j] = q[i][j - 1] * i;
      if (q[i][j] < 0 || q[i][j] >= N * 480) q[i][j] = -1;
    }
  }
  while (m--) {
    scanf("%d%s%I64d", &d, s, &c);
    ans = 99;
    x = y = 0;
    change(strlen(s), s, x, y);
    for (int i = 0; i < 5; i++)
      if (d == 2)
        work(g[i], a[i], ans);
      else
        work(f[d][i], a[i], ans);
    printf("%d\n", ans > 97 ? -1 : ans);
  }
  return 0;
}
