#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%I64d%I64d", &n, &m);
  long long sol = max(0LL, n - m * 2);
  printf("%I64d ", sol);
  for (int i = 0; i <= n; i++)
    if (1LL * i * (i - 1) / 2 >= m) {
      printf("%d", n - i);
      break;
    }
  return 0;
}
