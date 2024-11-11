#include <bits/stdc++.h>
using namespace std;
long long phi(long long n) {
  long long res = 1;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      long long p = i;
      n /= i;
      res *= p - 1;
      while (n % i == 0) n /= i, res *= p;
    }
  if (n > 1) res *= n - 1;
  return res;
}
int main() {
  int n, k;
  cin >> n >> k;
  while (n != 1) {
    if (k <= 0) break;
    n = phi(n);
    k -= 2;
  }
  cout << n % 1000000007LL << endl;
  return 0;
}
