#include <bits/stdc++.h>
using namespace std;
char s[1010];
int str[1010][30];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    int over = s[i] - 'a' + 1;
    for (int j = 1; j <= 26; j++) str[i][j] = str[i - 1][j];
    str[i][over]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      bool flag = 1;
      int len = j - i + 1, maxn = len / 2;
      for (int k = 1; k <= 26; k++) {
        if (str[j][k] - str[i - 1][k] > maxn) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        puts("YES");
        for (int k = i; k <= j; k++) putchar(s[k]);
        puts("");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
