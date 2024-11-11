#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x;
  cin >> t;
  while (t--) {
    cin >> x;
    int a, b;
    a = x % 14;
    b = x / 14;
    if ((a <= 6 && a >= 1) && b > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
