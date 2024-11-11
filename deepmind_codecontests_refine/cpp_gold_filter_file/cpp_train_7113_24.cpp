#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ll, rr;
  scanf("%d%d", &n, &k);
  for (ll = 1, rr = n; ll < rr;) {
    int mid = (ll + rr) / 2, v = mid, sum = 0;
    for (; v; v /= k) sum += v;
    if (sum == n) {
      cout << mid;
      return 0;
    }
    if (sum > n)
      rr = mid;
    else
      ll = mid + 1;
  }
  printf("%d\n", ll);
  return 0;
}
