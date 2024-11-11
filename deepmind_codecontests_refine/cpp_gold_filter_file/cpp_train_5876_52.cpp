#include <bits/stdc++.h>
int main() {
  char ch[102], mh[102];
  int i, j, flag = 0;
  gets(ch);
  gets(mh);
  for (i = 0; i < strlen(ch); i++) {
    if (ch[i] == mh[strlen(ch) - i - 1])
      flag = 1;
    else {
      flag = 0;
      break;
    }
  }
  if (flag == 0)
    printf("NO");
  else
    printf("YES");
  return 0;
}
