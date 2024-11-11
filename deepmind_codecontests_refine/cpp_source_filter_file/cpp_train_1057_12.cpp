#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
const int N = 2e5 + 5;
const int LOG_N = 25;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + b) / c << " ";
  a %= c;
  b %= c;
  if (a > b && (a + b) >= c) {
    cout << c - a << endl;
  } else if (b > a && (a + b) >= c) {
    cout << c - b << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
