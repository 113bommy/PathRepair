#include <bits/stdc++.h>
using namespace std;
long long gcd(long long m, long long n) { return n ? gcd(n, m % n) : m; }
int main() {
  long long n, k;
  cin >> n >> k;
  cout << min(n - k, 1LL) << " " << min(n - k, 2 * k) << endl;
}
