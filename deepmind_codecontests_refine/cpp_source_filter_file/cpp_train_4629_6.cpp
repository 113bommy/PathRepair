#include <bits/stdc++.h>
using namespace std;
int n, s;
int main() {
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (n % 2 == 1) {
    s = 6;
    cout << "1 + 4 = 5\n";
    cout << "5 * 5 = 25\n";
    cout << "2 - 3 = -1\n";
    cout << "25 - -1 = 24\n";
  } else {
    s = 5;
    int t = 1;
    for (int i = 2; i <= 4; i++) {
      cout << t << " * " << i << " = " << t * i << "\n";
      t *= i;
    }
  }
  for (int i = s; i <= n; i += 2) {
    cout << i + 1 << " - " << i << " = 1\n";
    cout << "24 * 1 = 24\n";
  }
  return 0;
}
