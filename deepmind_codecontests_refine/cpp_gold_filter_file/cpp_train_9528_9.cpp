#include <bits/stdc++.h>
using namespace std;
unsigned long long c(unsigned long long n, unsigned long long k) {
  if (k > n) return 0;
  unsigned long long res = 1;
  for (unsigned long long i = n - k + 1; i <= n - 1; i++) res *= i;
  for (unsigned long long i = 1; i <= k - 1; i++) res /= i;
  return res * n / k;
}
int main() {
  unsigned long long n;
  cin >> n;
  cout << c(n + 2, 3) * c(n + 4, 5);
  return 0;
}
