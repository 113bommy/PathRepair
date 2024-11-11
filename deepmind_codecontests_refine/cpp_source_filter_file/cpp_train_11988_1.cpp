#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int inf = 1e9;
const long long llf = 1e18;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int main() {
  int a;
  cin >> a;
  if (a == 2 || a == 3 || a == 4 || a == 5 || a == 46 || a == 12 || a == 30 ||
      a == 35 || a == 43 || a == 52 || a == 64 || a == 79) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
