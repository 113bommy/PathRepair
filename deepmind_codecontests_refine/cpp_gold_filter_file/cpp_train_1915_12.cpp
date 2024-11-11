#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, cnt1 = 0, cnt0 = 0, s;
  scanf("%d%d", &n, &m);
  while (n--) {
    scanf("%d", &x);
    if (x == 1)
      cnt1++;
    else
      cnt0++;
  }
  while (m--) {
    scanf("%d%d", &x, &y);
    s = y - x + 1;
    if (s == 1 || s % 2)
      printf("0\n");
    else if (s % 2 == 0) {
      if (cnt1 >= s / 2 && cnt0 >= s / 2)
        printf("1\n");
      else
        printf("0\n");
    }
  }
}
