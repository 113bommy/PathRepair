#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
long long n;
int k;
char ans[MAX];
int main() {
  srand(time(NULL));
  scanf("%lld%d", &n, &k);
  long long mid, left = 1, right = n;
  while (left <= right) {
    mid = left + (right - left) / 2;
    printf("%lld %lld\n", left, mid);
    fflush(stdout);
    scanf("%s", &ans);
    if (ans[0] == 'B') return 0;
    if (ans[0] == 'Y') {
      if (left == right) return 0;
      left = max(1LL, left - k);
      right = min(mid + k, n);
    } else {
      left = max(mid + 1 - k, 1LL);
      right = min(right + k, n);
    }
    while (right - left < 5 * k) {
      long long gas = rand() % (right - left + 1) + left;
      printf("%lld %lld\n", gas, gas);
      fflush(stdout);
      scanf("%s", &ans);
      if (ans[0] == 'Y') return 0;
      left = max(left - k, 1LL);
      right = min(right + k, n);
    }
  }
  return 0;
}
