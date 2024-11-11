#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  long long a[20];
  a[0] = 1;
  for (i = 1; i <= 18; i++) {
    a[i] = a[i - 1] * 10;
  }
  long long l, r;
  while (scanf("%I64d%I64d", &l, &r) != EOF) {
    int b, c;
    for (i = 18; i >= 0; i--) {
      if (l / a[i] >= 1) {
        b = i;
        break;
      }
    }
    for (i = 18; i >= 0; i--) {
      if (r / a[i] >= 1) {
        c = i;
        break;
      }
    }
    long long sum = 0;
    int flag = 0;
    if (b == 0) {
      if (c == 0) {
        flag = 1;
        sum = r - l + 1;
      } else {
        sum += 10 - l;
        l = 10;
      }
    }
    if (flag == 0) {
      long long s1, s2, w1, w2;
      s1 = l / a[b];
      s2 = l % 10;
      w1 = r / a[c];
      w2 = r % 10;
      long long ss1, ss2;
      if (s2 > s1) {
        ss1 = (l - l / a[b] * a[b]) / 10 + 1;
      } else {
        ss1 = (l - l / a[b] * a[b]) / 10;
      }
      if (w2 >= w1) {
        ss2 = (r - r / a[c] * a[c]) / 10;
      } else {
        ss2 = (r - r / a[c] * a[c]) / 10 - 1;
      }
      if (b == c) {
        if (s1 == w1) {
          sum += ss2 - ss1 + 1;
        } else {
          sum += a[b - 1] - ss1;
          sum += ss2 + 1;
          sum += a[b - 1] * (w1 - s1 - 1);
        }
      } else {
        sum += a[b - 1] - ss1;
        sum += a[b - 1] * (9 - s1);
        sum += ss2 + 1;
        sum += a[c - 1] * (w1 - 1);
        int k;
        for (i = b + 1; i < c; i++) {
          sum += a[i - 1] * 9;
        }
      }
    }
    printf("%I64d\n", sum);
  }
  return 0;
}
