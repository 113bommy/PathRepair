#include <bits/stdc++.h>
using namespace std;
long long n;
int k;
long long get_bound(int num) {
  long long ret = 0;
  long long nn = k - num + 1;
  ret = ret + k * nn;
  ret = ret - ((nn - 1) * nn) / 2 - nn;
  return ret + 1;
}
int main() {
  scanf("%I64d %d", &n, &k);
  int ans = -1;
  if (n == 1) {
    printf("0\n");
  } else if (n > get_bound(2)) {
    printf("-1\n");
  } else {
    int low = 1;
    int high = k - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) >> 1;
      if (n > get_bound(k - mid + 1)) {
        ans = mid + 1;
        low = mid + 1;
      } else if (n < get_bound(k - mid + 1)) {
        ans = mid;
        high = mid - 1;
      } else {
        ans = mid;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
