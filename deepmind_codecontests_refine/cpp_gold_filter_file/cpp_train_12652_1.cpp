#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, cnt;
  char str[10];
  while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
    getchar();
    scanf("%s", str);
    cnt = 0;
    int h = (str[0] - '0') * 10 + str[1] - '0';
    int m = (str[3] - '0') * 10 + str[4] - '0';
    int l = h * 60 + m;
    int r = l + b;
    int s = 300;
    while (s < r && s <= 23 * 60 + 59) {
      if (s + d > l) cnt++;
      s += c;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
