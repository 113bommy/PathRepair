#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, b;
  scanf("%d", &m) == 0, scanf("%d", &b) == 0;
  long long ans = 0;
  for (decltype((long long)0) i = (long long)0; i < b + 1; i++) {
    long long j = -(i - b) * m;
    long long rsum = (j * (j + 1)) / 2;
    long long usum = (i * (i + 1)) / 2;
    long long banans = rsum * (i + 1) + usum * (j + 1);
    ans = max(ans, banans);
  }
  printf("%I64d", ans);
}
