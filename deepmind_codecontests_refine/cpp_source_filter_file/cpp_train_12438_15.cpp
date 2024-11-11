#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 2e6 + 5, OO = 0x3f3f3f3f;
int n;
long long A[N];
bool canWeCover(long long d) {
  long long lastCovered = -OO, used = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] > lastCovered) {
      lastCovered = A[i] + 2 * d;
      used++;
    }
  }
  return used <= 3;
}
long long binarySearch() {
  long long lo = 0, mid, hi = 4e9;
  while (hi - lo > 0) {
    mid = (lo + hi) / 2;
    if (canWeCover(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", A + i);
  }
  sort(A, A + n);
  long long d = binarySearch();
  printf("%lf\n", d / 2.0);
  long long lastCovered = -OO, used = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] > lastCovered) {
      printf("%lf\n", A[i] + d / 2.0);
      lastCovered = A[i] + d;
      used++;
    }
  }
  while (used < 3) {
    puts("0");
    used++;
  }
  return 0;
}
