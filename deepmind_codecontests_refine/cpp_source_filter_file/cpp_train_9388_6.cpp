#include <bits/stdc++.h>
using namespace std;
int main() {
  long nTest;
  cin >> nTest;
  while (nTest--) {
    long nBlow, X;
    cin >> nBlow >> X;
    long MaxDamage = 0, MaxDecrease = 0;
    while (nBlow--) {
      long x, y;
      cin >> x >> y;
      MaxDamage = max(MaxDamage, x);
      MaxDecrease = max(MaxDecrease, x - y);
    }
    if (MaxDamage >= X)
      cout << "0\n";
    else if (MaxDecrease == 0)
      cout << "-1\n";
    else {
      X -= MaxDamage;
      cout << (X + MaxDecrease - 1) / MaxDecrease + 1 << '\n';
    }
  }
  flush(cout);
}
