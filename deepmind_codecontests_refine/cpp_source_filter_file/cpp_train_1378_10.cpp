#include <bits/stdc++.h>
using namespace std;
const long long sz = 5001;
const long long mod = 1e9 + 7;
long long power(long long n, long long k, long long m) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = (ans * n) % m;
    k /= 2;
    n = (n * n) % m;
  }
  return ans;
}
long long BIT[sz];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    cout << x << " " << 0 << "\n";
  }
  return 0;
}
