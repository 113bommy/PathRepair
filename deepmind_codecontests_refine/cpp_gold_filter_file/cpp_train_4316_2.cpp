#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, _;
  long long n, k, d1, d2;
  long long win[3];
  scanf("%d", &_);
  while (_--) {
    scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
    if (n % 3 != 0) {
      printf("no\n");
      continue;
    }
    int flag = 0;
    for (i = 0; i < 4; i++) {
      if (i == 0) {
        win[0] = d1 + d2;
        win[1] = d2;
        win[2] = 0;
        long long tmp = win[0] + win[1] + win[2];
        if (tmp > k) continue;
        if ((k - tmp) % 3 != 0) continue;
        if ((d1 + d2 + (k - tmp) / 3) * 3 <= n) flag = 1;
      }
      if (i == 1) {
        win[0] = d1;
        win[1] = 0;
        win[2] = d2;
        long long tmp = win[0] + win[1] + win[2];
        if (tmp > k) continue;
        if ((k - tmp) % 3 != 0) continue;
        if ((max(d1, d2) + (k - tmp) / 3) * 3 <= n) flag = 1;
      }
      if (i == 2) {
        win[1] = max(d1, d2);
        win[0] = win[1] - d1;
        win[2] = win[1] - d2;
        long long tmp = win[0] + win[1] + win[2];
        if (tmp > k) continue;
        if ((k - tmp) % 3 != 0) continue;
        if ((max(d1, d2) + (k - tmp) / 3) * 3 <= n) flag = 1;
      }
      if (i == 3) {
        win[0] = 0;
        win[1] = d1;
        win[2] = d1 + d2;
        long long tmp = win[0] + win[1] + win[2];
        if (tmp > k) continue;
        if ((k - tmp) % 3 != 0) continue;
        if ((d1 + d2 + (k - tmp) / 3) * 3 <= n) flag = 1;
      }
    }
    if (flag)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
