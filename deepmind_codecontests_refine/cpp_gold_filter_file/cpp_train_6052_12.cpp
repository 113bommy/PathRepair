#include <bits/stdc++.h>
const int M = 1005;
int main() {
  int i = 0, cnt1 = 0, cnt2 = 1;
  char s[M];
  scanf("%s", s);
  int t = strlen(s);
  while (i < t) {
    if (s[i] == '0') {
      cnt1++;
      if (cnt1 == 5) cnt1 = 1;
      printf("1 %d\n", cnt1);
    } else {
      cnt2 += 2;
      if (cnt2 == 5) cnt2 = 1;
      printf("3 %d\n", cnt2);
    }
    i++;
  }
  return 0;
}
