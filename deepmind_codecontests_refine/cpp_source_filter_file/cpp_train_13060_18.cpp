#include <bits/stdc++.h>
using namespace std;
long long fx[] = {-1, 1, 0, 0};
long long fy[] = {0, 0, -1, 1};
void Solution() {
  long long n;
  scanf("%lld", &n);
  if (n & 1)
    printf("%lld %lld\n", 9, n - 9);
  else
    printf("%lld %lld\n", 4, n - 4);
}
int32_t main() {
  long long tc = 1;
  for (long long tn = 1; tn < tc + 1; tn += 1) {
    Solution();
  }
  return 0;
}
