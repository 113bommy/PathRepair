#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long mod = 998244353;
vector<long long> d;
int main() {
  long long n;
  while (cin >> n) {
    d.push_back(0);
    d[0] = 1;
    long long x = 1;
    for (long long i = 1; i <= n; i++) {
      x = x * i % mod;
      ;
      d.push_back(0);
      d[i] = x + i * (d[i - 1] - 1);
    }
    cout << d[n] << endl;
  }
}
