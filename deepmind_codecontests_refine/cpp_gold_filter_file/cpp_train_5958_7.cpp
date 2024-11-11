#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, g, b;
    cin >> n >> g >> b;
    if (g >= b)
      cout << n << "\n";
    else {
      long long x = n / 2 + (n % 2);
      long long y = x / g + (x % g > 0) - 1;
      cout << max(n, y * (g + b) + (x - y * g)) << "\n";
    }
  }
  return 0;
}
