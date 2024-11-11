#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d, des;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> d;
    des = pow(d, 2) - 4 * d;
    if (d == 0) {
      cout << "0.000000000 0.000000000\n";
      continue;
    }
    if (d < 4) {
      cout << "N\n";
    } else {
      cout << "Y ";
      cout << fixed << setprecision(9) << ((-d) - sqrt(des)) / (-2) << " "
           << fixed << setprecision(9) << ((-d) + sqrt(des)) / (-2) << endl;
    }
  }
  return 0;
}
