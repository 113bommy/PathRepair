#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long X = 1000000007;
  long long sol = 1;
  if (k == n) {
    for (long long i = 1; i <= (n + 1) / 2; i++) {
      sol = (sol * m) % X;
    }
    cout << sol;
    return 0;
  }
  if (k > n || k == 1) {
    for (long long i = 1; i <= n; i++) {
      sol = (sol * m) % X;
    }
    cout << sol;
    return 0;
  }
  if (k % 2 == 1 && k < n) {
    sol = (m * m) % X;
    cout << sol;
  }
  if (k % 2 == 0 && k < n) {
    sol = m % X;
    cout << sol;
  }
  return 0;
}
