#include <bits/stdc++.h>
int main() {
  char com[101];
  int peo = 0, tra = 0;
  while (gets(com)) {
    if (com[0] == '+') {
      ++peo;
      continue;
    }
    if (com[0] == '-') {
      --peo;
      continue;
    }
    tra += (strlen(com) - (strchr(com, ':') - (com + 0) + 1)) * peo;
  }
  printf("%d\n", tra);
  return 0;
}
