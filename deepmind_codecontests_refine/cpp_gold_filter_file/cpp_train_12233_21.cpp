#include <bits/stdc++.h>
using namespace std;
long long ans = 0, i, j, n, m;
long long w[1100000], a[1100000];
vector<long long> v;
bool isPrime(long long x) {
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main() {
  cin >> n;
  long long ans = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans *= i;
    }
  }
  if (n) ans *= n;
  cout << ans << endl;
}
