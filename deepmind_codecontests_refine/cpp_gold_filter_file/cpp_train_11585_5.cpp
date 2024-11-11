#include <bits/stdc++.h>
using namespace std;
int main() {
  long long al;
  cin >> al;
  while (al--) {
    long long b, c;
    cin >> b >> c;
    if ((abs(b - c)) % 10 == 0)
      cout << abs(b - c) / 10 << "\n";
    else {
      b = abs(b - c);
      cout << b / 10 + 1 << "\n";
    }
  }
}
