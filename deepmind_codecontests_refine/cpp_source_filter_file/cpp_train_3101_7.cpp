#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((sqrt(a) + sqrt(b) - 1e-11 < sqrt(c)) ? "Yes" : "No") << "\n";
}
