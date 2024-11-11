#include <bits/stdc++.h>
using namespace std;
char s[15];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    int f = 0;
    for (int i = 5; i <= 9; i++) {
      int cnt10 = 0, cnt20 = 0, cnt11 = 0, cnt21 = 0;
      for (int j = 1; j <= i; j += 2) {
        if (s[j] == '1') {
          cnt10++;
          cnt11++;
        }
        if (s[j] == '?') {
          cnt11++;
        }
      }
      for (int j = 2; j <= i; j += 2) {
        if (s[j] == '1') {
          cnt20++;
          cnt21++;
        }
        if (s[j] == '?') {
          cnt21++;
        }
      }
      if ((cnt21 - cnt10 > (10 - i) / 2) ||
          (cnt11 - cnt20 > (10 - i + 1) / 2)) {
        printf("%d\n", i);
        f = 1;
        break;
      }
    }
    if (f == 0) {
      puts("10");
    }
  }
}
