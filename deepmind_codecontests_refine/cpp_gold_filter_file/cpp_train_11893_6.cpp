#include <bits/stdc++.h>
using namespace std;
long long k;
signed main() {
  cin >> k;
  cout << 2 << ' ' << 3 << "\n";
  long long base = 131072;
  cout << base + k << ' ' << base << ' ' << base << ' ' << "\n";
  cout << k << ' ' << base + k << ' ' << k;
  return 0;
}
