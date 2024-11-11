#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, k;
char hv[N][N], rv[N][N];
int ans[N][N];
void Read(char &c) {
  while (c = getchar(), c != 'E' && c != 'N')
    ;
}
void Init() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) Read(hv[i][j]);
    if (i != n)
      for (int j = 1; j <= m; j++) Read(rv[j][i]);
  }
}
void Work1() {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m - 1; j++)
      if (hv[i][j] == 'N') sum++;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n - 1; j++)
      if (rv[i][j] == 'N') sum++;
  if (sum * 4 >= (n * (m - 1) + m * (n - 1)) * 3) {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j != 1) putchar(' ');
        putchar('1');
      }
      puts("");
    }
  } else
    puts("NO");
}
void Work2(char hv[N][N], char rv[N][N]) {
  for (int i = 1; i <= n; i++) {
    int *t1 = ans[i], *t2 = ans[i - 1];
    for (int j = 1; j <= m - 1; j++) {
      t1[j + 1] = t1[j];
      if (hv[i][j] == 'N') t1[j + 1] ^= 1;
    }
    int temp = 0;
    for (int j = 1; j <= m; j++)
      if ((t1[j] == t2[j]) ^ (rv[j][i - 1] == 'N')) temp++;
    if (temp + temp < m)
      for (int j = 1; j <= m; j++) t1[j] ^= 1;
  }
}
int main() {
  Init();
  if (k == 1)
    Work1();
  else {
    puts("YES");
    if (n <= m) {
      Work2(hv, rv);
      for (int i = 1; i <= n; i++) {
        printf("%d", ans[i][1] + 1);
        for (int j = 2; j <= m; j++) printf(" %d", ans[i][j] + 1);
        puts("");
      }
    } else {
      int temp = n;
      n = m;
      m = temp;
      Work2(rv, hv);
      for (int i = 1; i <= m; i++) {
        printf("%d", ans[1][i] + 1);
        for (int j = 2; j <= n; j++) printf(" %d", ans[j][i] + 1);
        puts("");
      }
    }
  }
  return 0;
}
