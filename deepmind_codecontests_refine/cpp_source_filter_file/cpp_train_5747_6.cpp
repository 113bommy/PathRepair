#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n < 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  long long num = n;
  if (isprime(n)) {
    cout << n;
    return;
  }
  map<long long, long long> m;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      m[i]++;
    }
    if (m.size() >= 2) break;
  }
  if (n > 1) m[n]++;
  if (m.size() == 1) {
    cout << num / m.begin()->first;
  } else {
    cout << 1;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
