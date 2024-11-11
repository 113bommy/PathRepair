#include <bits/stdc++.h>
using namespace std;
long long fact(long long x) { return x ? x * fact(x - 1) : 1; }
int main() {
  int n;
  long long res = 0;
  cin >> n;
  int finalMask = 1 << n;
  for (int mask = 0; mask < finalMask; mask++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (mask & (1 << i));
    res += (cnt == n / 2);
  }
  res /= 2;
  res *= fact(n / 2 - 1) * fact(n / 2 - 1);
  cout << res << "\n";
  return 0;
}
