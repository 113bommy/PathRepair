#include <bits/stdc++.h>
using namespace std;
int n, m, K;
int s1[1010][1010], s2[1010][1010], num[1010][1010];
char ch[1010];
void solve() {
  int i, j, k;
  int tot = (n - 1) * m + (m - 1) * n;
  if (K == 1) {
    int num = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m - 1; j++)
        if (s1[i][j] == 0) num++;
    for (i = 1; i <= n - 1; i++)
      for (j = 1; j <= m; j++)
        if (s2[i][j] == 0) num++;
    if (num * 4 >= tot * 3) {
      printf("YES\n");
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) printf("1 ");
        printf("\n");
      }
    } else
      printf("NO\n");
    return;
  }
  if (n * (m - 1) >= m * (n - 1)) {
    for (i = 1; i <= n; i++) {
      num[i][1] = 0;
      for (j = 1; j <= m - 1; j++) {
        num[i][j + 1] = num[i][j] ^ s1[i][j];
      }
    }
    for (i = 1; i <= n - 1; i++) {
      int Num = 0;
      for (j = 1; j <= m; j++) {
        int pos = s2[i][j];
        if (pos == 0 && num[i][j] != num[i + 1][j]) Num++;
        if (pos == 1 && num[i][j] == num[i + 1][j]) Num++;
      }
      if (Num > m / 2) {
        for (j = 1; j <= m; j++) num[i + 1][j] ^= 1;
      }
    }
    printf("YES\n");
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) printf("%d ", num[i][j] + 1);
      printf("\n");
    }
  } else {
    for (i = 1; i <= m; i++) {
      num[1][i] = 0;
      for (j = 1; j <= n - 1; j++) {
        num[j + 1][i] = num[j][i] ^ s2[j][i];
      }
    }
    for (i = 1; i <= m - 1; i++) {
      int Num = 0;
      for (j = 1; j <= n; j++) {
        int pos = s1[j][i];
        if (pos == 0 && num[j][i] != num[j][i + 1]) Num++;
        if (pos == 1 && num[j][i] == num[j][i + 1]) Num++;
      }
      if (Num > n / 2) {
        for (i = 1; i <= n; i++) num[j + 1][i] ^= 1;
      }
    }
    printf("YES\n");
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) printf("%d ", num[i][j] + 1);
      printf("\n");
    }
  }
}
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &m, &K);
  for (i = 1; i <= n - 1; i++) {
    scanf("%s", ch);
    for (j = 1; j <= m - 1; j++) {
      if (ch[j - 1] == 'E')
        s1[i][j] = 0;
      else
        s1[i][j] = 1;
    }
    scanf("%s", ch);
    for (j = 1; j <= m; j++) {
      if (ch[j - 1] == 'E')
        s2[i][j] = 0;
      else
        s2[i][j] = 1;
    }
  }
  scanf("%s", &ch);
  for (j = 1; j <= m - 1; j++) {
    if (ch[j - 1] == 'E')
      s1[n][j] = 0;
    else
      s1[n][j] = 1;
  }
  solve();
}
