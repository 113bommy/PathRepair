#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  double s, a, b, c;
  cin >> s >> a >> b >> c;
  int sum = a + b + c;
  cout << setprecision(18) << fixed;
  if (sum) {
    cout << (a * s) / sum << " ";
    cout << (b * s) / sum << " ";
    cout << (c * s) / sum << endl;
  } else {
    cout << "0 0 0 " << endl;
  }
  return 0;
}
