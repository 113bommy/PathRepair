#include <bits/stdc++.h>
using namespace std;
int s[100010], num[100010];
int main() {
  int Max = 100010;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    for (int left = a, step = 0; left < Max; left = (left << 1), step++) {
      s[left] += step;
      num[left]++;
    }
    for (int right = a, step = 0; right > 0;) {
      if (right % 2 == 1) {
        right = (right >> 1), step++;
        s[right] += step;
        num[right]++;
        for (int left = right, addstep = step;;) {
          left = (left << 1);
          addstep++;
          if (left > Max || left == 0) break;
          num[left]++;
          s[left] += addstep;
        }
      } else {
        right = (right >> 1), step++;
        s[right] += step;
        num[right]++;
      }
    }
  }
  int I;
  int ans = 1000000000;
  for (int i = 1; i < Max; i++) {
    if (num[i] == n) {
      ans = min(ans, s[i]);
      I = i;
    }
  }
  printf("%d\n", ans);
}
