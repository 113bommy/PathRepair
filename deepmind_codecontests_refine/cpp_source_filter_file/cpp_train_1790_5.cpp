#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n > 2 && n % 2 == 0)
      cout << 0 << "\n";
    else if (n > 2 && n % 2 == 1)
      cout << 1;
    else
      cout << 4 - n << "\n";
  }
}
