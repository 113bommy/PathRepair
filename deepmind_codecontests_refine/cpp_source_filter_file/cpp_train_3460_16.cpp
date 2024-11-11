#include <bits/stdc++.h>
using namespace std;
long long fact(long long x) {
  if (x == 1) return 1;
  return x * fact(x - 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << "\n" << c << "\n" << d << endl;
  }
  return 0;
}
