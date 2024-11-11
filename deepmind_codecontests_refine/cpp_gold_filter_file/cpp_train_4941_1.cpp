#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int main() {
  scanf("%I64d", &n);
  for (long long i = 1; i < 1111111; ++i) {
    long long tp = (n - i * 2);
    if (tp < 0) continue;
    if (tp % 3 != 0) continue;
    tp /= 3;
    if (tp >= i * (i - 1) / 2) ++ans;
  }
  printf("%I64d", ans);
  return 0;
}
