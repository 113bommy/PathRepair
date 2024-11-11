#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n;
    cin >> a >> b >> n;
    if (n == 0)
      cout << a << "\n";
    else if (n == 1)
      cout << b << "\n";
    else if (n % 3 == 0)
      cout << a << "\n";
    else if (n % 2 == 1)
      cout << b << "\n";
    else
      cout << (a ^ b) << "\n";
  }
  return 0;
}
