#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long n;
    cin >> n;
    long long power;
    for (power = 1; power <= n; power <<= 1)
      ;
    cout << n * (n + 1) / 2 - 2 * (power - 1);
  }
  return 0;
}
