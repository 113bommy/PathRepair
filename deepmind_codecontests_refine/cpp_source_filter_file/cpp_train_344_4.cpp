#include <bits/stdc++.h>
const int maxn = 5010;
char s[maxn];
char t[maxn];
int a[30], b[30];
int main() {
  int i, j, k, l;
  bool can, flag;
  while (scanf("%s%s", s, t) != EOF) {
    can = true;
    int lens = strlen(s);
    int lent = strlen(t);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (i = 0; i < lens; i++) a[s[i] - 'a']++;
    for (i = 0; i < lent; i++) b[t[i] - 'a']++;
    int more = 0;
    for (i = 0; i < 26; i++) {
      if (a[i] < b[i]) can = false;
      if (a[i] > b[i]) more++;
    }
    int cnt;
    if (can && more) {
      cnt = lent;
      for (i = 0; i < 26; i++)
        for (j = 0; j < a[i] - b[i]; j++) t[cnt++] = 'a' + i;
      t[cnt] = '\0';
      printf("%s\n", t);
      continue;
    }
    flag = false;
    for (i = lent - 1; i >= 0; i--) {
      can = true;
      b[t[i] - 'a']--;
      for (j = 0; j < 26; j++)
        if (a[j] < b[j]) can = false;
      if (!can) continue;
      for (j = 0; j < 26; j++)
        if (j > t[i] - 'a' && a[j] > b[i]) {
          flag = true;
          a[j]--;
          t[i] = 'a' + j;
          cnt = i + 1;
          for (i = 0; i < 26; i++)
            for (j = 0; j < a[i] - b[i]; j++) t[cnt++] = 'a' + i;
          t[cnt] = 0;
          printf("%s\n", t);
          break;
        }
      if (flag) break;
    }
    if (!flag) printf("-1\n");
  }
  return 0;
}
