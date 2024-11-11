#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const long long INF = 0x7fffffffffffffff;
const int mod = 1e9 + 7;
int n, k;
int arr[500005];
bool C(int t) {
  int *it = lower_bound(arr, arr + n, t);
  int cnt = 0;
  for (int *ptr = arr; ptr != it; ptr++) {
    cnt += (t - *ptr);
    if (cnt > k) return false;
  }
  return cnt <= k;
}
bool D(int t) {
  int *it = upper_bound(arr, arr + n, t);
  int cnt = 0;
  for (; it != arr + n; it++) {
    cnt += ((*it) - t);
    ;
    if (cnt > k) return false;
  }
  return cnt <= k;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  long long tot = 0;
  for (int i = 0; i < n; i++) tot += arr[i];
  sort(arr, arr + n);
  int low;
  int lb = arr[0], ub = arr[n - 1] + 1;
  ;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    if (C(mid))
      lb = mid;
    else
      ub = mid;
  }
  low = lb;
  lb = arr[0] - 1, ub = arr[n - 1];
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    if (D(mid))
      ub = mid;
    else
      lb = mid;
  }
  int high = ub;
  (void)0;
  if (low > high)
    printf("%d\n", (tot % n) != 0);
  else
    cout << high - low << endl;
  return 0;
}
