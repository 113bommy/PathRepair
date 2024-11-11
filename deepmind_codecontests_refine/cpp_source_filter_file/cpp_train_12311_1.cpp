#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > c)
      cout << -1 << " ";
    else
      cout << 1 << " ";
    if (a * b < c)
      cout << -1 << " ";
    else
      cout << b << " " << endl;
  }
  return 0;
}
