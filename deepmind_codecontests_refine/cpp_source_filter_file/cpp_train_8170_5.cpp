#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (a < b) {
    cout << "-1";
    return 0;
  }
  long long first = a + b;
  long long second = first / 2 * b;
  second = second * 2;
  double ans = (first * 1.0) / (second * 1.0);
  cout << setprecision(12) << fixed << ans;
}
