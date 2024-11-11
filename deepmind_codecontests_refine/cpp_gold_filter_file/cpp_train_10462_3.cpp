#include <bits/stdc++.h>
using namespace std;
long long Count(int a, int b, int c, int lft) {
  if (a < b + c) return 0;
  long long t = min(lft, a - (b + c));
  return (t + 1LL) * (t + 2LL) / 2LL;
}
int main() {
  int a, b, c, l;
  while (scanf("%d%d%d%d", &a, &b, &c, &l) != EOF) {
    long long ans = 1LL * (l + 1) * (l + 2) * (l + 3) / 6;
    for (int i = 0; i <= l; i++) {
      ans -= Count(a + i, b, c, l - i) + Count(b + i, a, c, l - i) +
             Count(c + i, a, b, l - i);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
