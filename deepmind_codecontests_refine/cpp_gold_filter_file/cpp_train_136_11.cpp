#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, a, b, c, v;
  cin >> a >> b >> c;
  v = a * c;
  v -= b * c;
  cout << (v - 1) / b + 1;
  return 0;
}
