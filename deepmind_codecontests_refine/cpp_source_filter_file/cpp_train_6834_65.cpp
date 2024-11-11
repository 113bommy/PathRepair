#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  if (n > 36) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < n / 2; i++) {
    cout << "8";
  }
  for (long long i = 0; i < n % 2; i++) {
    cout << "0";
  }
}
