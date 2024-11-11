#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  for (int x = 0; x < k; x++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > (b * c)) {
      cout << -1;
    } else {
      long long cp = (a / b / d);
      long long r = (a * (cp + 1)) - ((b * (cp + 1) * (cp * d)) / 2);
      cout << r << "\n";
    }
  }
}
