#include <bits/stdc++.h>
using namespace std;
int ball[200020];
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a == 0 || b <= 1) {
    printf("%I64d\n", 1LL * a * a - 1LL * b * b);
    for (int i = 0; i < a; ++i) printf("o");
    for (int i = 0; i < b; ++i) printf("x");
    return 0;
  }
  long long ans = -(1LL << 55);
  int dig;
  for (int i = 2; i <= b; ++i) {
    if (i - 1 > a) break;
    int cntb = b / i;
    int yu = b - cntb * i;
    long long tmp =
        -1LL * yu * (cntb + 1) * (cntb + 1) - 1LL * (i - yu) * cntb * cntb;
    tmp += 1LL * (a - (i - 2)) * (a - (i - 2)) + i - 2;
    if (tmp > ans) {
      ans = tmp;
      dig = i;
    }
  }
  printf("%I64d\n", ans);
  int cntb = b / dig;
  int yu = b - cntb * dig;
  for (int i = 0; i < dig; ++i) ball[i * 2] = -cntb;
  for (int i = 0; i < yu; ++i) ball[i * 2]--;
  ball[1] = a - (dig - 2);
  for (int i = 3; ball[i + 1]; i += 2) ball[i] = 1;
  for (int i = 0; ball[i]; ++i) {
    if (ball[i] < 0) {
      ball[i] *= -1;
      for (int j = 0; j < ball[i]; ++j) printf("x");
    } else {
      for (int j = 0; j < ball[i]; ++j) printf("o");
    }
  }
  return 0;
}
