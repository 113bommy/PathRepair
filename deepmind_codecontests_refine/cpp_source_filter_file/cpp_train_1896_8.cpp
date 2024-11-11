#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    long long q = x % 14;
    if (x > 14 && q >= 1 && q <= 6)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
