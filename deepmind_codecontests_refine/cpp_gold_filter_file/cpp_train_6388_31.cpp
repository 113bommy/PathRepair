#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n > 2)
      cout << n - 2 << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}
