#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n + 1; ++i) {
    long long res = i * (i + 1) / 2;
    if (n < res) return cout << i - 1, 0;
    n -= res;
  }
}
