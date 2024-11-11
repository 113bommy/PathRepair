#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (long long i = 5; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_set<long long> second;
  for (long long i = 0; i <= 1000; i++) {
    second.insert((i * i));
  }
  long long n;
  cin >> n;
  long long ans = -1;
  while (n--) {
    long long x;
    cin >> x;
    if (second.count(x) == 0) {
      ans = max(ans, x);
    }
  }
  cout << ans;
  return 0;
}
