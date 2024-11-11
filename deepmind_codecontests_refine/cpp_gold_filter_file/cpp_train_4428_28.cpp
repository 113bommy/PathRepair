#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a;
  if (a == 0)
    cout << 1;
  else {
    b = 10 * (a - 1);
    cout << b + (a - 1) * (3 * a - 4) + 7;
  }
}
