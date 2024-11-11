#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mn, min2;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int a, b, c;
  cin >> a >> b >> c;
  mn = min(a, min(b, c));
  if (a == mn || b == mn)
    cout << mn * (n - 1);
  else {
    min2 = min(a, b);
    cout << mn + min2 * (n - 2);
  }
}
