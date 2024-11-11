#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, p = 1;
  char ch = getchar();
  while (!(('0' <= ch && ch <= '9') || ch == '-')) ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while ('0' <= ch && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * p;
}
const int maxn = 1e6 + 20;
int n;
int op[maxn], ch[maxn][2];
char str[100];
int val[maxn];
int p[maxn][2][21];
int deep[maxn];
void dfs(int u) {
  if (op[u] == 4) return;
  int le = ch[u][0], re = ch[u][1];
  if (le) deep[le] = deep[u] + 1, dfs(le);
  if (re) deep[re] = deep[u] + 1, dfs(re);
  if (op[u] == 3) {
    val[u] = !val[le];
    p[le][0][0] = ((u) + (1) * n);
    p[le][1][0] = ((u) + (0) * n);
  } else if (op[u] == 2) {
    val[u] = val[le] ^ val[re];
    p[le][0][0] = ((u) + (0 ^ val[re]) * n);
    p[le][1][0] = ((u) + (1 ^ val[re]) * n);
    p[re][0][0] = ((u) + (0 ^ val[le]) * n);
    p[re][1][0] = ((u) + (1 ^ val[le]) * n);
  } else if (op[u] == 1) {
    val[u] = val[le] | val[re];
    p[le][0][0] = ((u) + (0 | val[re]) * n);
    p[le][1][0] = ((u) + (1 | val[re]) * n);
    p[re][0][0] = ((u) + (0 | val[le]) * n);
    p[re][1][0] = ((u) + (1 | val[le]) * n);
  } else {
    val[u] = val[le] & val[re];
    p[le][0][0] = ((u) + (0 & val[re]) * n);
    p[le][1][0] = ((u) + (1 & val[re]) * n);
    p[re][0][0] = ((u) + (0 & val[le]) * n);
    p[re][1][0] = ((u) + (1 & val[le]) * n);
  }
}
inline void init() {
  n = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) {
    scanf("%s", str);
    if (str[0] == 'A')
      op[i] = 0;
    else if (str[0] == 'O')
      op[i] = 1;
    else if (str[0] == 'X')
      op[i] = 2;
    else if (str[0] == 'N')
      op[i] = 3;
    else
      op[i] = 4;
    int x = read(), y = 0;
    if (op[i] < 3) y = read();
    if (op[i] <= 3)
      ch[i][0] = x, ch[i][1] = y;
    else
      val[i] = x;
  }
  dfs(1);
  for (int j = (1), _end_ = (20); j <= _end_; j++)
    for (int i = (1), _end_ = (n); i <= _end_; i++)
      for (int t = (0), _end_ = (1); t <= _end_; t++) {
        int x = p[i][t][j - 1];
        int x1 = x, x2 = 0;
        if (x > n) x2 = 1, x1 = x - n;
        p[i][t][j] = p[x1][x2][j - 1];
      }
}
inline void doing() {
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    if (op[i] == 4) {
      int u = i, now = val[i] ^ 1, dis = deep[i];
      for (int j = (20), _end_ = (0); j >= _end_; j--)
        if (dis >> j & 1) {
          int x = p[u][now][j];
          int x1 = x, x2 = 0;
          if (x > n) x2 = 1, x1 = x - n;
          u = x1;
          now = x2;
        }
      printf("%d", now);
    }
}
int main() {
  init();
  doing();
  return 0;
}
