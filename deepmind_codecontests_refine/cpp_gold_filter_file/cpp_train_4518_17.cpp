#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int x;
int tavan(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) ans *= a;
  return ans;
}
int main() {
  cin >> a >> b >> n;
  bool neg = false;
  bool sol = true;
  if (a == 0 && b != 0)
    sol = false;
  else if (a == 0 && b == 0) {
    cout << 1 << endl;
    return 0;
  } else if (b == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (a < 0 && b < 0) {
    a = -a;
    b = -b;
  } else if (a < 0 || b < 0) {
    if (n % 2 == 0)
      sol = false;
    else {
      neg = true;
      a = (a > 0) ? a : -a;
      b = (b > 0) ? b : -b;
    }
  }
  if (sol) {
    sol = false;
    x = 1;
    while (tavan(x, n) * a <= b) {
      int temp = tavan(x, n) * a;
      if (temp == b) {
        sol = true;
        break;
      }
      x++;
    }
  }
  if (!sol)
    cout << "No solution" << endl;
  else if (neg)
    cout << -x << endl;
  else
    cout << x << endl;
  return 0;
}
