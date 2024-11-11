#include <bits/stdc++.h>
const int maxn = 100010;
char str1[maxn], str2[maxn];
char ans[maxn];
void getNextDiff(char *&s1, char *&s2, char *&sa) {
  while (*s1 == *s2) {
    *sa = *s1;
    s1++;
    s2++;
    sa++;
  }
}
char getDiffChar(char a, char b) {
  char re = 'a';
  while (re == a || re == b) re++;
  return re;
}
int main() {
  int n, t, m, l;
  while (scanf("%d%d", &n, &t) == 2) {
    scanf("%s%s", str1, str2);
    m = 0;
    for (int i = 0; i < n; i++)
      if (str1[i] != str2[i]) m++;
    if (m > 2 * t) {
      printf("-1\n");
      continue;
    }
    l = m - t;
    char *s1 = str1, *s2 = str2, *sa = ans;
    if (l > 0) {
      for (int i = 0; i < l; i++) {
        getNextDiff(s1, s2, sa);
        *sa = *s1;
        sa++;
        s1++;
        s2++;
      }
      for (int i = 0; i < l; i++) {
        getNextDiff(s1, s2, sa);
        *sa = *s2;
        sa++;
        s1++;
        s2++;
      }
      for (int i = 0; i < t - l; i++) {
        getNextDiff(s1, s2, sa);
        *sa = getDiffChar(*s1, *s2);
        sa++;
        s1++;
        s2++;
      }
      while (*s1 != NULL) {
        *sa = *s1;
        s1++;
        sa++;
      }
    } else {
      l = t - m;
      for (int i = 0; i < l; i++) {
        while (*s1 != *s2) {
          *sa = getDiffChar(*s1, *s2);
          s1++;
          s2++;
          sa++;
        }
        *sa = getDiffChar(*s1, *s1);
        s1++;
        s2++;
        sa++;
      }
      while (*s1 != NULL) {
        if (*s1 == *s2) {
          *sa = *s1;
          sa++;
          s1++;
          s2++;
        } else {
          *sa = getDiffChar(*s1, *s2);
          s1++;
          s2++;
          sa++;
        }
      }
    }
    *sa = 0;
    puts(ans);
  }
  return 0;
}
