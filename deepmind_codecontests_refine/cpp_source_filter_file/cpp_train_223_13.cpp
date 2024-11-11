#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n, c;
    cin >> a >> b >> n;
    c = b ^ a;
    if (n % 3 == 0)
      cout << b << '\n';
    else if (n % 3 == 1)
      cout << a << '\n';
    else
      cout << c << '\n';
  }
}
