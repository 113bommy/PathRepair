#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((sqrtl(a) + sqrtl(b) + 1e-13 < sqrtl(c)) ? "Yes" : "No") << "\n";
}
