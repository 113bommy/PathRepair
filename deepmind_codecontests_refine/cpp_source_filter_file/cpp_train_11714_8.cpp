#include <bits/stdc++.h>
using namespace std;
int main() {
  long double d, l, v1, v2;
  cin >> d >> l >> v1 >> v2;
  cout.precision(6);
  cout << (l - d) / (v1 + v2);
  return 0;
}
