#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("avx2,tune=native")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  if (n < 3)
    cout << n;
  else if (n & 1)
    cout << n * (n - 1) * (n - 2);
  else if (n % 3 == 0)
    cout << (n - 1) * (n - 2) * (n - 3);
  else
    cout << n * (n - 1) * (n - 2);
  return 0;
}
