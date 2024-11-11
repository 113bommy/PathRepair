#include <bits/stdc++.h>
using namespace std;
const int N = 100000000 + 7;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum = 1;
  for (int i = 1; i <= n - k; ++i) {
    sum *= (n - k);
    if (sum >= N) sum %= N;
  }
  for (int i = 2; i <= k; ++i) {
    sum *= k;
    if (sum >= N) sum %= N;
  }
  printf("%I64d\n", sum);
  return 0;
}
