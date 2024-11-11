#include <bits/stdc++.h>
using namespace std;
bool f(int a, int b) {
  if (b > a + 1) return false;
  while (a > 2) {
    a -= 2;
    b--;
  }
  if (b >= 0)
    return true;
  else
    return false;
}
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (f(c, b) or f(d, a))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
