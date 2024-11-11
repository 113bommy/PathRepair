#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101000;
int dp[MAX_N];
int b[MAX_N][12];
char st[MAX_N], s[MAX_N];
int a[MAX_N], cnt = 0;
void print(int x) {
  int i;
  if (cnt > 10) {
    for (i = 1; i <= 5; i++) b[x][i] = a[cnt - i + 1];
    b[x][6] = a[2];
    b[x][7] = a[1];
  } else {
    for (i = 1; i <= cnt; i++) b[x][i] = a[cnt - i + 1];
  }
}
int pre[MAX_N];
int main(void) {
  int n, i, j;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  s[n + 1] = 'a' - 1;
  a[0] = n + 1;
  for (i = n; i >= 1; i--) {
    if (s[a[cnt]] != s[i]) {
      a[++cnt] = i;
      pre[cnt] = cnt - 1;
    } else if (s[a[cnt]] == s[i]) {
      if (a[cnt] == i + 1) {
        if (s[a[pre[cnt]]] > s[i]) {
          a[++cnt] = i;
          pre[cnt] = pre[cnt - 1];
        } else {
          cnt--;
        }
      } else {
        a[++cnt] = i;
        pre[cnt] = pre[cnt - 1];
      }
    }
    dp[i] = cnt;
    print(i);
  }
  for (i = 1; i <= n; i++) {
    printf("%d ", dp[i]);
    if (dp[i] > 10) {
      for (j = 1; j <= 5; j++) printf("%c", s[b[i][j]]);
      printf("...");
      for (j = 6; j <= 7; j++) printf("%c", s[b[i][j]]);
    } else {
      for (j = 1; j <= dp[i]; j++) printf("%c", s[b[i][j]]);
    }
    printf("\n");
  }
  return 0;
}
