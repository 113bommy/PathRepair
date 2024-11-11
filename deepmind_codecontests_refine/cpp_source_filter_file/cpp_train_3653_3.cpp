#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, m, a, b, x, y;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> m;
  if (m % 2) {
    x = (m + 1) / 2;
    y = (m + 1) / 2;
  } else {
    x = m / 2 + 1;
    y = m / 2;
  }
  if (a > b) {
    for (int i = 1; i <= a - x + 1; i++) cout << "0";
    for (int i = 1; i <= b - y + 1; i++) cout << "1";
    for (int i = 1; i < y; i++) cout << "01";
    if (x > y) cout << "0" << endl;
  } else {
    for (int i = 1; i <= a - x + 1; i++) {
      cout << "1";
    }
    for (int i = 1; i <= b - y + 1; i++) {
      cout << "0";
    }
    for (int i = 1; i < y; i++) {
      cout << "10";
    }
    if (x > y) cout << "1" << endl;
  }
  return 0;
}
