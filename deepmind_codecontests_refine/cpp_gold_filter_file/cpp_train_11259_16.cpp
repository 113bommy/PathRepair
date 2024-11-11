#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, m1 = 10, m2 = 1e7;
  cin >> n >> k;
  int x[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> m1;
    if (x[i] < k) {
      x[i] += ((k - x[i]) / m1) * m1;
    }
    if (x[i] < k) {
      x[i] += m1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (m2 > x[i]) {
      k = i + 1;
      m2 = x[i];
    }
  }
  cout << k << endl;
  return 0;
}
