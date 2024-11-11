#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    bool flag = false;
    for (int i = 0; i <= 3; i++) {
      int t = (n - i * 7);
      if (t < 0) break;
      if (t % 4 == 0) {
        int num_4 = t / 4;
        int num_7 = i + ((num_4) / 7) * 4;
        num_4 %= 7;
        for (int j = 0; j < num_4; j++) putchar('4');
        for (int j = 0; j < num_7; j++) putchar('7');
        putchar('\n');
        flag = true;
        break;
      }
    }
    if (!flag) puts("-1");
  }
  return 0;
}
