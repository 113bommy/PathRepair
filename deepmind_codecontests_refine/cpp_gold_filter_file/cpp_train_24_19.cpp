#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long c = 0, c1 = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[n - 1] >= (a[0] + a[1])) {
      cout << 1 << " " << 2 << " " << n << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
