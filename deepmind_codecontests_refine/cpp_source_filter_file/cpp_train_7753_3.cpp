#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int bin[30], bin2[10], v[35][35];
int n, m, ed, top;
int a[25], b[25];
vector<int> q[25];
bool f[25][32][161051];
char ans[10][25];
struct data {
  int a, b;
};
void p(int sta) {
  for (int i = 1; i <= n; i++)
    if (sta & bin[i - 1])
      ans[i][top] = '*';
    else
      ans[i][top] = '.';
  top--;
}
void dfs(int x, int tot, int sta, bool last) {
  if (x == n + 1) {
    q[tot].push_back(sta);
    return;
  }
  dfs(x + 1, tot + (!last), sta + bin[x - 1], 1);
  dfs(x + 1, tot, sta, 0);
}
bool dfs2(int i, int t1, int k) {
  f[i][t1][k] = 1;
  if (i == m) {
    if (k == ed) {
      p(t1);
      return 1;
    }
    return 0;
  }
  for (int y = 0; y < q[b[i + 1]].size(); y++) {
    int t2 = q[b[i + 1]][y];
    int nk = k + v[t1][t2];
    if (nk <= ed)
      if (!f[i + 1][t1][k])
        if (dfs2(i + 1, t2, nk)) {
          p(t1);
          return 1;
        }
  }
  return 0;
}
int main() {
  bin[0] = 1;
  for (int i = 1; i < 30; i++) bin[i] = bin[i - 1] << 1;
  bin2[0] = 1;
  for (int i = 1; i < 10; i++) bin2[i] = bin2[i - 1] * 11;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  for (int i = 1; i <= n; i++) ed += a[i] * bin2[i - 1];
  dfs(1, 0, 0, 0);
  for (int t1 = 0; t1 <= bin[n] - 1; t1++)
    for (int t2 = 0; t2 <= bin[n] - 1; t2++)
      for (int l = 1; l <= n; l++)
        if ((t2 & bin[l - 1]) && (t1 & bin[l - 1]) == 0)
          v[t1][t2] += bin2[l - 1];
  top = m;
  dfs2(0, 0, 0);
  for (int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
  return 0;
}
