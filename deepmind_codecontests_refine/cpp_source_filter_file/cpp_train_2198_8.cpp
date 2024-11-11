#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long a;
    cin >> a;
    long long count = 0;
    while (a > 0) {
      if (a % 2 == 1) count++;
      a /= 2;
    }
    long long res = 1;
    for (int j = 0; j < count; ++j) res *= 2;
    cout << res;
  }
}
