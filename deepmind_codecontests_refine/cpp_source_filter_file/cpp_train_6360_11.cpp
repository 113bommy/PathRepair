#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c1 = 0, c0 = 0, n1 = 0, n0 = 0;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1')
      c1++;
    else
      c0++;
    if (a[i] == '0' && b[i] == '0')
      n1++;
    else if (a[i] == '1' && b[i] == '0')
      n0++;
  }
  cout << (n1 * c1) + (n0 * abs(c0 - n1));
  return 0;
}
