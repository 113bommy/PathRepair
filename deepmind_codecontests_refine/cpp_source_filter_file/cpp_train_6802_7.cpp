#include <bits/stdc++.h>
using namespace std;
int S;
int a, b, c;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> S >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) return cout << "0 0 0" << endl, 0;
  double sum = a + b + c;
  double factor = S / sum;
  cout << fixed << setprecision(9) << a * factor << " " << b * factor << " "
       << c * factor << endl;
  return 0;
}
