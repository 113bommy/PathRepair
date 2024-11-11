#include <bits/stdc++.h>
using namespace std;
long long int arr1[1111111], arr2[1111111];
int main(void) {
  long long int n, k, k2;
  cin >> n >> k;
  k2 = k;
  for (int e = n - 1; e >= 0; e--) {
    arr1[n - 1 - e] = e + 1;
    arr2[n - 1 - e] = e + 1;
  }
  long long int l = (n * (n + 1)) / 2;
  long long int tmp = (n / 2);
  long long int r = (n * (n + 1)) - (tmp * (tmp + 1));
  if (n % 2) r -= (tmp + 1);
  if (k < l) {
    printf("-1");
    return 0;
  }
  k -= l;
  priority_queue<long long int> q;
  for (int e = 1; e < n; e++) q.push((long long int)e);
  for (int e = 0; e < n; e++) {
    while (!q.empty()) {
      long long int t = q.top();
      q.pop();
      t -= e;
      if (t <= 0) continue;
      if (k >= t) {
        k -= t;
        swap(arr2[e + t], arr2[e]);
        break;
      }
    }
  }
  printf("%lld\n", min(r, k2));
  for (int e = 0; e < n; e++) printf("%lld ", arr1[e]);
  printf("\n");
  for (int e = 0; e < n; e++) printf("%lld ", arr2[e]);
  return 0;
}
