#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b, s;
  cin >> a >> b >> s;
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  if (a + b <= s && (s - (a + b)) % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
