#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5;
const long long mod = 1e9 + 7;
vector<long long> prime(10000000, 1);
long long z = INT_MIN;
void isPrime() {
  long long c = 0;
  for (long long p = 2; p * p <= 10000000; p++)
    if (prime[p] == 1)
      for (long long i = p * 2; i <= 10000000; i += p) {
        prime[i] = 0;
      }
}
void in(long long n, long long a[]) {
  z = INT_MIN;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > z) z = a[i];
  }
}
void out(long long n, long long a[]) {
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long c0 = 0, c1 = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      c1++;
    } else if (a[i] == 0)
      c0++;
  }
  cout << c1 * (pow(2, c0)) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
