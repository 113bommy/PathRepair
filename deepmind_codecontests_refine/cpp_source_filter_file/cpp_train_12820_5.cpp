#include <bits/stdc++.h>
using namespace std;
const int M = 260, N = 1e5 + 10, C = 26;
char s[N];
int f[M][M][M];
int nxt[N][C];
int a[N], b[N], c[N];
int lena, lenb, lenc, inf;
int n, Q, m;
void prework() {
  for (int i = 0; i < C; ++i) nxt[n + 1][i] = nxt[n][i] = n + 1;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < C; ++j) nxt[i - 1][j] = nxt[i][j];
    nxt[i - 1][s[i] - 'a'] = i;
  }
  for (int i = 0; i <= 250; ++i)
    for (int j = 0; j <= 250; ++j)
      for (int k = 0; k <= 250; ++k) f[i][j][k] = inf;
}
void upd(int &x, int y) { x = min(x, y); }
void clear(int x) {
  if (x == 1) {
    for (int i = 1; i <= lenb + 1; ++i)
      for (int j = 1; j <= lenc + 1; ++j) f[lena + 1][i][j] = inf;
    a[lena--] = ' ';
  } else if (x == 2) {
    for (int i = 1; i <= lena + 1; ++i)
      for (int j = 1; j <= lenc + 1; ++j) f[i][lenb + 1][j] = inf;
    b[lenb--] = ' ';
  } else {
    for (int i = 1; i <= lena + 1; ++i)
      for (int j = 1; j <= lenb + 1; ++j) f[i][j][lenc + 1] = inf;
    c[lenc--] = ' ';
  }
}
void insert(int which, int ch) {
  if (which == 1) {
    a[++lena] = ch;
    for (int i = 1; i <= lenb + 1; ++i)
      for (int j = 1; j <= lenc + 1; ++j) {
        upd(f[lena + 1][i][j], nxt[f[lena][i][j]][ch]);
        if (i < lenb + 1)
          upd(f[lena + 1][i + 1][j], nxt[f[lena + 1][i][j]][b[i]]);
        if (j < lenc + 1)
          upd(f[lena + 1][i][j + 1], nxt[f[lena + 1][i][j]][c[j]]);
      }
  } else if (which == 2) {
    b[++lenb] = ch;
    for (int i = 1; i <= lena + 1; ++i)
      for (int j = 1; j <= lenc + 1; ++j) {
        upd(f[i][lenb + 1][j], nxt[f[i][lenb][j]][ch]);
        if (i < lena + 1)
          upd(f[i + 1][lenb + 1][j], nxt[f[i][lenb + 1][j]][a[i]]);
        if (j < lenc + 1)
          upd(f[i][lenb + 1][j + 1], nxt[f[i][lenb + 1][j]][c[j]]);
      }
  } else if (which == 3) {
    c[++lenc] = ch;
    for (int i = 1; i <= lena + 1; ++i)
      for (int j = 1; j <= lenb + 1; ++j) {
        upd(f[i][j][lenc + 1], nxt[f[i][j][lenc]][ch]);
        if (i < lena + 1)
          upd(f[i + 1][j][lenc + 1], nxt[f[i][j][lenc + 1]][a[i]]);
        if (j < lenb + 1)
          upd(f[i][j + 1][lenc + 1], nxt[f[i][j][lenc + 1]][b[j]]);
      }
  }
}
int main() {
  char op[10], ch[10];
  int x;
  scanf("%d%d", &n, &Q);
  scanf("%s", s + 1);
  inf = n + 1;
  prework();
  lena = lenb = lenc = 0;
  f[1][1][1] = 0;
  for (int i = 1; i <= Q; ++i) {
    scanf("%s", op);
    if (op[0] == '+') {
      scanf("%d", &x);
      scanf("%s", ch);
      insert(x, ch[0] - 'a');
    } else {
      scanf("%d", &x);
      clear(x);
    }
    if (f[lena + 1][lenb + 1][lenc + 1] <= n)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
