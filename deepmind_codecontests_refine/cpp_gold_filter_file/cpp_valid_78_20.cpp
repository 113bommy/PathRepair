#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if ((b % 2) == 0)
      s = (b / 2) + 1;
    else
      s = ((b + 1) / 2);
    if (s >= a)
      cout << b % s << endl;
    else
      cout << b % a << endl;
  }
  return 0;
}
