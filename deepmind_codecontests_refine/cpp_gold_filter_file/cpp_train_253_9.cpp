#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s[maxn];
int d[maxn][3];
int e = 0;
int main() {
  scanf("%s", s);
  int now = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(')
      now++;
    else if (s[i] == ')') {
      now--;
      if (now < 0) {
        printf("-1\n");
        return 0;
      }
    } else {
      now--;
      if (now < 0) {
        printf("-1\n");
        return 0;
      }
      d[e][0] = now;
      d[e][1] = 1;
      d[e][2] = i;
      e++;
    }
  }
  if (now < 0)
    printf("-1\n");
  else {
    if (now <= d[e - 1][0]) {
      d[e - 1][0] -= now;
      d[e - 1][1] += now;
      now = d[e - 1][0];
      for (int i = d[e - 1][2] + 1; s[i]; i++) {
        if (s[i] == '(')
          now++;
        else {
          now--;
          if (now < 0) {
            printf("-1\n");
            return 0;
          }
        }
      }
      for (int i = 0; i < e; i++) {
        printf("%d\n", d[i][1]);
      }
    } else {
      printf("-1\n");
      return 0;
    }
  }
  return 0;
}
