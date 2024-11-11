#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
signed main() {
  long long n, a, b, c;
  cin >> a >> b >> c >> n;
  long long A = a - c;
  long long B = b - c;
  if (A < 0 || B < 0 || n - (A + B + c) <= 0)
    cout << -1 << endl;
  else
    cout << n - A - B - c << endl;
  return 0;
}
