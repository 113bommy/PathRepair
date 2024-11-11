#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  unsigned long long t;
  cin >> t;
  unsigned long long n, k;
  for (unsigned long long i = 0; i < t; i++) {
    unsigned long long dv;
    cin >> n >> k;
    if (n & 1) {
      dv = n;
      for (unsigned long long i = 3; i * i <= n; i++) {
        if (n % i == 0) {
          dv = i;
          break;
        }
      }
      cout << n + dv + 2 * (k - 1);
    } else
      cout << n + 2 * k;
    cout << "\n";
  }
  return 0;
}
