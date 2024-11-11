#include <bits/stdc++.h>
long long erg[100000][4];
char str1[100000];
char str2[100000];
void handle(char s1, char s2, int i) {
  if (s1 > s2) {
    erg[i][1] += erg[i - 1][0];
    erg[i][3] += erg[i - 1][2];
    erg[i][3] += erg[i - 1][3];
    erg[i][1] += erg[i - 1][1];
  } else if (s1 < s2) {
    erg[i][2] += erg[i - 1][0];
    erg[i][3] += erg[i - 1][1];
    erg[i][2] += erg[i - 1][2];
    erg[i][3] += erg[i - 1][3];
  } else {
    erg[i][0] += erg[i - 1][0];
    erg[i][1] += erg[i - 1][1];
    erg[i][2] += erg[i - 1][2];
    erg[i][3] += erg[i - 1][3];
  };
  erg[i][0] %= 1000000007;
  erg[i][1] %= 1000000007;
  erg[i][2] %= 1000000007;
  erg[i][3] %= 1000000007;
};
int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", str1);
  scanf("%s", str2);
  erg[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    char s1 = str1[i - 1];
    char s2 = str2[i - 1];
    if (s1 != '?') {
      if (s2 != '?') {
        handle(s1, s2, i);
      } else {
        for (char j = '0'; j <= '9'; j++) {
          handle(s1, j, i);
        };
      };
    } else {
      for (char j = '0'; j <= '9'; j++) {
        if (s2 != '?') {
          handle(j, s2, i);
        } else {
          for (char k = '0'; k <= '9'; k++) {
            handle(j, k, i);
          };
        };
      };
    };
  };
  printf("%d\n", erg[n][3]);
  return 0;
};
