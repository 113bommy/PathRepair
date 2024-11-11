#include <bits/stdc++.h>
struct data {
  int a0, a1, a2;
};
using namespace std;
int main() {
  int la, lb, n, i, j, k, l, m, left, right, mid, f[51][51];
  bool a[51][51][27], b[51][51][27];
  string ta, tb;
  data w[51];
  memset(a, false, sizeof(a));
  memset(b, false, sizeof(b));
  cin >> ta >> tb;
  la = ta.size();
  lb = tb.size();
  for (i = 1; i <= la; i++) a[i][i][int(ta[i - 1]) - 96] = true;
  for (i = 1; i <= lb; i++) b[i][i][int(tb[i - 1]) - 96] = true;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    cin >> ta;
    w[i].a0 = int(ta[0]) - 96;
    w[i].a1 = int(ta[3]) - 96;
    w[i].a2 = int(ta[4]) - 96;
  }
  for (i = 1; i < la; i++) {
    for (left = 1; left <= la - i; left++) {
      right = left + i;
      for (j = 1; j <= n; j++)
        if (!a[left][right][w[j].a0]) {
          for (mid = left; mid < right; mid++)
            if (a[left][mid][w[j].a1] && a[mid + 1][right][w[j].a2]) {
              a[left][right][w[j].a0] = true;
              break;
            }
        }
    }
  }
  for (i = 1; i < lb; i++) {
    for (left = 1; left <= lb - i; left++) {
      right = left + i;
      for (j = 1; j <= n; j++)
        if (!b[left][right][w[j].a0]) {
          for (mid = left; mid < right; mid++)
            if (b[left][mid][w[j].a1] && b[mid + 1][right][w[j].a2]) {
              b[left][right][w[j].a0] = true;
              break;
            }
        }
    }
  }
  for (i = 0; i <= la; i++)
    for (j = 0; j <= lb; j++) f[i][j] = INT_MAX / 10;
  f[0][0] = 0;
  for (i = 1; i <= la; i++)
    for (j = 1; j <= lb; j++)
      for (k = 1; k <= i; k++)
        for (l = 1; l <= j; l++)
          for (m = 1; m <= 26; m++)
            if (a[k][i][m] && b[l][j][m]) {
              if (f[i][j] > f[k - 1][l - 1] + 1) f[i][j] = f[k - 1][l - 1] + 1;
              break;
            }
  if (f[la][lb] < INT_MAX / 10)
    printf("%d", f[la][lb]);
  else
    printf("-1");
  return (0);
}
