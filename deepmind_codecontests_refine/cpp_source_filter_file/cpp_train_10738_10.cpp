#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];
long long n, m;
long long coun(long long x) {
  if (x == 0) return 1;
  long long l = x, coun = 0;
  for (long long i = 0; i < x; i++) {
    while (arr[l] - arr[i] < m && l < n) l++;
    if (arr[l] - arr[i] >= m && l < n) {
      coun++;
      l++;
    }
  }
  if (coun == x)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long l = 0, r = n - 1;
  while (r - l > 3) {
    long long f1 = l + (r - l) / 3;
    long long f2 = r - (r - l) / 3;
    if (coun(f1) <= coun(f2)) {
      l = f1;
    } else {
      r = f2;
    }
  }
  for (long long i = r; i >= l; i--) {
    if (coun(i)) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
