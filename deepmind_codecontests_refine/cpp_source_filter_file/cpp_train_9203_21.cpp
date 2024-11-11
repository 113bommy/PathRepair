#include <bits/stdc++.h>
const double Pi = 3.14159265;
const double e = 2.71828182;
const int N = 1e3 + 5;
const unsigned long long base = 163;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a, b, c, d;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
    if (a + c <= n) {
      cout << i + 1 << " " << a << " " << n - c << endl;
      return 0;
    }
    if (a + d <= n) {
      cout << i + 1 << " " << a << " " << n - d << endl;
      return 0;
    }
    if (b + c <= n) {
      cout << i + 1 << " " << b << " " << n - b << endl;
      return 0;
    }
    if (b + d <= n) {
      cout << i + 1 << " " << b << " " << n - d << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
