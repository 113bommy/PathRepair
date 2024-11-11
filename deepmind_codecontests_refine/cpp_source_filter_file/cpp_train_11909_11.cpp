#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  if (n & 1 == 0)
    cout << "-1\n";
  else {
    for (long long i = 0; i < n; i++) {
      cout << i << " \n"[i == n - 1];
    }
    for (long long i = 0; i < n; i++) {
      cout << i << " \n"[i == n - 1];
    }
    for (long long i = 0; i < n; i++) {
      cout << (2 * i) % n << " \n"[i == n - 1];
    }
  }
  return 0;
}
