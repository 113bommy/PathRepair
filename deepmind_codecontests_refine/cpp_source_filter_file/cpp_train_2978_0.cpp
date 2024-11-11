#include <bits/stdc++.h>
using namespace std;
long long ans = INT_MAX;
long long sod(long long num) {
  long long ans = 0;
  while (num) {
    ans += num % 10;
    num /= 10;
  }
  return ans;
}
void binarySearch(long long low, long long high, long long s) {
  if (high < low) return;
  long long mid = low + (high - low) / 2;
  long long temp = mid - sod(mid);
  if (temp == s) {
    high = mid - 1;
    if (mid < ans) ans = mid;
  } else if (temp > s) {
    high = mid - 1;
    if (mid < ans) ans = mid;
  } else
    low = mid + 1;
  binarySearch(low, high, s);
}
signed main() {
  long long n, s;
  cin >> n >> s;
  ans = n;
  binarySearch(1, n, s);
  if (n == ans) {
    long long temp = (n / 10) * 9;
    if (temp >= s)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  } else
    cout << n - ans + 1 << endl;
}
