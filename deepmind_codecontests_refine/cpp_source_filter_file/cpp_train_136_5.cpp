#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, a, b, c, v;
  cin >> a >> b >> c;
  v = a * c;
  v -= b * c;
  cout << max((v - 1) / b + 1, c);
  return 0;
}
