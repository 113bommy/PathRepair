#include <bits/stdc++.h>
int num[105];
char ch[102][105];
int del[105];
int i_del[105];
char c[105];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", del + i);
    i_del[del[i]] = 1;
  }
  strcpy(c, ch[del[0]]);
  int l = strlen(ch[del[0]]);
  int flag = 1;
  for (int i = 1; i < m; i++) {
    if (strlen(ch[del[i]]) != l) {
      flag = 0;
      break;
    }
    for (int j = 0; j < l; j++) {
      if (c[j] != '?' && c[j] != ch[del[i]][j]) {
        c[j] = '?';
      }
    }
  }
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if (i_del[i] == 0) {
      if (strlen(ch[i]) == l) {
        for (int j = 0; j < l; j++) {
          if (c[j] == '?' || c[j] == ch[i][j]) {
            t = 1;
          } else {
            t = 0;
            break;
          }
        }
        if (t == 1) {
          break;
        }
      }
    }
  }
  if (flag && !t) {
    printf("Yes\n%s\n", c);
  } else {
    printf("No\n");
  }
}
