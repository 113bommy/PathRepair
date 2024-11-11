#include <bits/stdc++.h>
using namespace std;
char s[100011];
int main() {
  int cnt(0), cs(0), lstcnt, lst, i;
  scanf("%s", s);
  for (i = 0; s[i]; ++i) {
    if (s[i] == '(')
      ++cnt;
    else if (s[i] == ')')
      --cnt;
    else if (s[i] == '#') {
      ++cs;
      lst = i;
      lstcnt = cnt;
    }
    if (cnt < cs) {
      printf("-1\n");
      return 0;
    }
  }
  for (i = lst, lstcnt = lstcnt - cnt + cs; s[i]; ++i) {
    if (s[i] == '(')
      ++lstcnt;
    else if (s[i] == ')')
      --lstcnt;
    if (lstcnt < cs) {
      printf("-1\n");
      return 0;
    }
  }
  for (i = 1; i < cs; ++i) printf("1\n");
  printf("%d\n", cnt - cs + 1);
  return 0;
}
