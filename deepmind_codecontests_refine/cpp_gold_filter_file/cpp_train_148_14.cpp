#include <bits/stdc++.h>
using namespace std;
long long int GCD(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
bool isPerfectSq(int x) {
  long long int lo = 1, hi = x;
  while (lo <= hi) {
    long long int mid = (lo + hi) >> 1;
    if (mid * mid == x)
      return true;
    else if (mid * mid < x)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return false;
}
bool prime[1000009];
void primeSieve() {
  memset(prime, 1, sizeof(prime));
  prime[0] = 0, prime[1] = 0;
  for (int i = 2; i * i < 1000009; i++) {
    for (int j = i * i; j < 1000009; j += i) {
      if (prime[i] == 1) {
        prime[j] = 0;
      }
    }
  }
}
void solve();
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) solve();
  return 0;
}
void solve() {
  int sum = 0;
  int t = 5;
  while (t--) {
    int k;
    cin >> k;
    sum += k;
  }
  if (!sum || sum % 5)
    cout << -1 << '\n';
  else
    cout << (sum / 5) << '\n';
  return;
}
