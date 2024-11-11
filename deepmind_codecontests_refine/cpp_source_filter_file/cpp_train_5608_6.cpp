#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
    cout << 0;
  else
    cout << min(a * b, min(b * c, c * a));
  return 0;
}
