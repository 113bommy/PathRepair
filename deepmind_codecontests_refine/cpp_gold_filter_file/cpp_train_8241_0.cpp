#include <bits/stdc++.h>
using namespace std;
unsigned long long sum[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 6, 10, 15, 21, 28, 36, 45},
    {0, 2, 6, 12, 20, 20, 22, 26, 32, 40},
    {0, 3, 9, 18, 20, 25, 33, 34, 38, 45},
    {0, 4, 12, 14, 20, 20, 24, 32, 34, 40},
    {0, 5, 5, 10, 10, 15, 15, 20, 20, 25},
    {0, 6, 8, 16, 20, 20, 26, 28, 36, 40},
    {0, 7, 11, 12, 20, 25, 27, 36, 42, 45},
    {0, 8, 14, 18, 20, 20, 28, 34, 38, 40},
    {0, 9, 17, 24, 30, 35, 39, 42, 44, 45},
};
unsigned long long solve(unsigned long long n, unsigned long long k) {
  unsigned long long ans = sum[k][n % 10];
  n /= 10;
  unsigned long long p = sum[k][9];
  while (n > 0) {
    ans = ans + (n % 10) * p;
    n /= 10;
    p *= 10;
  }
  return ans;
}
int main() {
  unsigned long long t;
  cin >> t;
  unsigned long long m, n;
  while (t--) {
    cin >> n >> m;
    if (m == n) {
      cout << m % 10 << "\n";
      continue;
    } else if (m > n || m == 0) {
      cout << "0\n";
      continue;
    } else {
      unsigned long long k = m % 10;
      unsigned long long num = n / m;
      if (num == 1) {
        cout << k << endl;
        continue;
      }
      unsigned long long ans = solve(num, k);
      cout << ans << endl;
    }
  }
}
