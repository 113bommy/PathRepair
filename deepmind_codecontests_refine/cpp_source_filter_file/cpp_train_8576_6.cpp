#include <bits/stdc++.h>
using namespace std;
int main() {
  signed int n;
  cin >> n;
  if (n >= 0)
    cout << n;
  else {
    if (n == -10)
      cout << 0;
    else {
      int rem = n % 10;
      int x = n / 10;
      int y = (n / 10) * 10 + rem;
      cout << max(x, y);
    }
  }
  return 0;
}
