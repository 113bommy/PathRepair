#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, p, q;
  cin >> l >> p >> q;
  cout.precision(10);
  cout << (float)l * p / (p + q);
  return 0;
}
