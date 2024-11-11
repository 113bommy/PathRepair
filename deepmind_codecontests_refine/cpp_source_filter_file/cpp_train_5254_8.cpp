#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
int arr[1000006];
int lowerit(int val, int n) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] < val && (mid == n - 1 || arr[mid + 1] >= val))
      return arr[mid];
    else if (val >= arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main() {
  int n, maxit = -(int)(1e9 + 7), ans = 0, i, val, val1, findit;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    maxit = ((maxit) > (arr[i]) ? (maxit) : (arr[i]));
  }
  sort(arr, arr + n);
  for (i = 0; i < n; ++i) {
    val = arr[i];
    if (i != 0 && val == arr[i - 1]) continue;
    val1 = 2 * val;
    while (1) {
      findit = lowerit(val1, n);
      if (findit < val) {
        if (val1 >= maxit) break;
        val1 += val;
        continue;
      }
      findit %= val;
      ans = ((ans) > (findit) ? (ans) : (findit));
      if (val1 >= maxit) break;
      val1 += val;
    }
  }
  printf("%d\n", ans);
  return 0;
}
