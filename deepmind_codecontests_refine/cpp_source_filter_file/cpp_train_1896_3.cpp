#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    if (x / 14 >= 1 && 1 <= x % 14 && x % 14 <= 6)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
