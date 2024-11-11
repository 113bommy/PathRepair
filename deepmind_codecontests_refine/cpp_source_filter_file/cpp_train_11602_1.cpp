#include <bits/stdc++.h>
const int N = 100050;
int f[N][27];
int main() {
  int n;
  scanf("%d", &n);
  int m = 0;
  while (n--) {
    char c = getchar();
    for (; (c < 'a' || c > 'z') && c != '?'; c = getchar())
      ;
    int i = 1;
    for (; (c >= 'a' && c < 'z') || c == '?'; c = getchar(), i++) {
      if (c == '?')
        f[i][26] = 1;
      else
        f[i][c - 'a'] = 1;
    }
    m = i - 1;
  }
  for (int i = 1; i <= m; i++) {
    int k = 0;
    for (int j = 0; j <= 26; j++)
      if (f[i][j]) k++;
    if (k >= 3)
      printf("?");
    else if (k == 1) {
      if (f[i][26])
        printf("a");
      else {
        for (int j = 0; j <= 25; j++)
          if (f[i][j]) printf("%c", 'a' + j);
      }
    } else {
      if (!f[i][26])
        printf("?");
      else {
        for (int j = 0; j <= 25; j++)
          if (f[i][j]) printf("%c", 'a' + j);
      }
    }
  }
}
