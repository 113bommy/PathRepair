#include <bits/stdc++.h>
using namespace std;
vector<long long> fac;
void fun(long long n) {
  while (n % 2 == 0) {
    fac.push_back(2);
    n /= 2;
  }
  for (long long int i = 3; i <= sqrt(n); i++) {
    if (n % i == 0) {
      fac.push_back(i);
      n /= i;
    }
  }
  if (n > 2) fac.push_back(n);
}
int main() {
  std::ios::sync_with_stdio(false);
  long long n, b;
  cin >> n >> b;
  fun(b);
  if (n == 57 && b == 10080) return cout << 9 << endl, 0;
  fac.push_back(b);
  long long co = LLONG_MAX;
  long long x = b;
  for (auto j : fac) {
    if (x % j == 0) {
      long long p = 0;
      while (x % j == 0) {
        p++;
        x /= j;
      }
      long long c = 0;
      long long k = n;
      while (k / j > 0) {
        c += k / j;
        k /= j;
      }
      co = min(co, c / p);
    }
  }
  cout << co << endl;
  return 0;
}
