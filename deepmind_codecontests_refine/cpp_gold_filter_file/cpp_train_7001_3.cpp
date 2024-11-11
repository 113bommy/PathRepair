#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, i, j, k, l, p, q, r = 0, s = 1;
  scanf("%lld", &c);
  while (c--) {
    char s1[55], s2[] = "abacaba", s3[55];
    scanf("%lld %s", &a, &s1);
    a = strlen(s1);
    b = strlen(s2);
    k = 0;
    for (i = 0; i < a - 6; i++) {
      l = i;
      for (j = 0; j < b; j++) {
        if (s1[l] != s2[j]) break;
        l++;
      }
      if (j == b) k++;
    }
    if (k > 1)
      printf("No\n");
    else if (k == 1) {
      printf("Yes\n");
      for (i = 0; i < a; i++) {
        if (s1[i] == '?')
          printf("z");
        else
          printf("%c", s1[i]);
      }
      printf("\n");
    } else {
      k = 0;
      for (i = 0; i < a - 6; i++) {
        l = i;
        for (j = 0; j < 11 && l < a; j++) {
          if (j < 7)
            r = j;
          else
            r = j % 7 + 3;
          if (j >= 7 && s1[l] == '?') break;
          if (s1[l] != s2[r] && s1[l] != '?') break;
          l++;
        }
        if (j < 11 && j > 6) {
          l = 0;
          for (j = i; j < i + 7; j++) {
            if (s1[j] == '?') s1[j] = s2[l];
            l++;
          }
          k = 1;
          break;
        } else if (j == 11) {
          for (j = i; j < i + 4; j++) {
            if (s1[j] == '?') break;
          }
          if (j == i + 4)
            i = i + 7;
          else
            i = i + 3;
        }
      }
      if (k == 0)
        printf("No\n");
      else {
        printf("Yes\n");
        for (i = 0; i < a; i++) {
          if (s1[i] == '?')
            printf("z");
          else
            printf("%c", s1[i]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
