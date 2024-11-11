#include <bits/stdc++.h>
using namespace std;
bool g(int a, int b) {
  if ((a - b <= 1) and
      ((b % 2 > 0 and a >= b / 2) or (b % 2 == 0 and a >= (b / 2) - 1)))
    return 1;
  else
    return 0;
}
int main() {
  int a2, a1, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  if ((g(a1, b2) == 1) or (g(a2, b2) == 1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
