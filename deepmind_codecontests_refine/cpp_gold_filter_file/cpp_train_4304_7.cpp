#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i;
  while (scanf("%I64d", &i) != EOF) {
    long long ans = (3 * i - 1) * (3 * i - 2) / 2 + 3 * i * (i - 1) / 2;
    printf("%I64d\n", ans);
  }
  return 0;
}
