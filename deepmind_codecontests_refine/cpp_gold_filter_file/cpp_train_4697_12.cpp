#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
using std::string;
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  long long t, n, k, m, a, b, c;
  cin >> a >> b >> c;
  if (a >= b + c) {
    cout << a - b - c + 1;
  } else if (b >= a + c) {
    cout << b - a - c + 1;
  } else if (c >= a + b) {
    cout << c - a - b + 1;
  } else {
    cout << 0;
  }
  return 0;
}
