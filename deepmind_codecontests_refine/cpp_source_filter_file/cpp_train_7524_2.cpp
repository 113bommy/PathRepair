#include <bits/stdc++.h>
int A[26];
int B[27];
char s[100001], p[100001];
int main() {
  int i, j, sl, pl, t = 0, flag;
  gets(s);
  gets(p);
  sl = strlen(s);
  pl = strlen(p);
  for (i = 0; p[i]; i++) {
    A[p[i] - 'a']++;
  }
  if (pl < sl) {
    for (j = 0; j < pl; j++) {
      if (s[j] == '?')
        B[26]++;
      else {
        B[s[j] - 'a']++;
      }
    }
    flag = 0;
    for (j = 0; j < 26; j++) {
      if (A[j] < B[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      t++;
    }
  }
  for (i = 1; s[i] && i + pl <= sl; i++) {
    flag = 0;
    if (s[i - 1] == '?')
      B[26]--;
    else
      B[s[i - 1] - 'a']--;
    if (s[i + pl - 1] == '?')
      B[26]++;
    else
      B[s[i + pl - 1] - 'a']++;
    for (j = 0; j < 26; j++) {
      if (A[j] < B[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      t++;
    }
  }
  printf("%d", t);
  return 0;
}
