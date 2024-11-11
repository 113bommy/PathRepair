#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    long long log = 0, n;
    scanf("%I64d", &n);
    while (1 << (log + 1) <= n) log++;
    long long sum = ((n + 1) * n >> 1) - ((1 << (log + 2)) - 2);
    printf("%I64d\n", sum);
  }
  return 0;
}
