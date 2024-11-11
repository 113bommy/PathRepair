#include <bits/stdc++.h>
using namespace std;
int a[100][26] = {0};
int flag[100] = {0};
int main() {
  int t;
  char c;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int j, flag1 = 1;
    memset(a, 0, sizeof(a));
    memset(flag, 0, sizeof(flag));
    if (i == 0) getchar();
    for (int i = 0; i < 3; i++) {
      for (j = 0;; j++) {
        scanf("%c", &c);
        if (c != '\n') {
          a[j][c - 'a']++;
          if (i == 2)
            if (a[j][c - 'a'] >= 2) flag[j] = 1;
        } else {
          break;
        }
      }
    }
    for (int i = 0; i < j; i++) {
      if (flag[i] != 1) flag1 = 0;
    }
    if (flag1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
