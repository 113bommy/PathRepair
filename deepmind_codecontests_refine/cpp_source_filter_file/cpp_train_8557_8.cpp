#include <bits/stdc++.h>
using namespace std;
bool check(long long x, long long n, long long k) {
  long long ans = 0;
  long long i = 0;
  if (x % 2 == 0) i++;
  for (; x <= n; i++) {
    long long temp = (1 << i);
    if ((n - x) > temp) {
      ans += temp;
      x *= 2;
    } else {
      ans += n - x + 1;
      break;
    }
  }
  return ans >= k;
}
long long getMaxEven(long long n, long long k) {
  long long l = 1, r = n;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid % 2 == 1) mid++;
    if (check(mid, n, k))
      l = mid + 2;
    else
      r = mid - 2;
  }
  if (r % 2 == 0)
    return r;
  else
    return l - 2;
}
long long getMaxOdd(long long n, long long k) {
  long long l = 1, r = n;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid % 2 == 0) mid++;
    if (check(mid, n, k))
      l = mid + 2;
    else
      r = mid - 2;
  }
  if (r % 2 == 1)
    return r;
  else
    return l - 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  long long maxEven, maxOdd;
  cin >> n >> k;
  maxEven = getMaxEven(n, k);
  maxOdd = getMaxOdd(n, k);
  cout << max(maxEven, maxOdd) << endl;
  return 0;
}
