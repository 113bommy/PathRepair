#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
int32_t main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  long long x = 4;
  long long sum = 1;
  for (long long i = 2; i <= n; i++) {
    sum += (i - 1) * 4;
  }
  cout << sum << endl;
}
