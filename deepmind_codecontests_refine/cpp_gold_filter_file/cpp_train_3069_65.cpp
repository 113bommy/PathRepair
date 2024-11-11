#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = 2 * acos(0.0);
const long long MX = 2e5 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  char c[9][9];
  ll p = INT_MAX, q = INT_MAX, r = INT_MAX, s = INT_MAX;
  ll x = 0, y = 0;
  for (ll i = 0; i < 8; i++) {
    for (ll j = 0; j < 8; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'N') x += 3;
      if (c[i][j] == 'Q') x += 9;
      if (c[i][j] == 'B') x += 3;
      if (c[i][j] == 'R') x += 5;
      if (c[i][j] == 'P') x += 1;
      if (c[i][j] == 'q') y += 9;
      if (c[i][j] == 'b') y += 3;
      if (c[i][j] == 'r') y += 5;
      if (c[i][j] == 'p') y += 1;
      if (c[i][j] == 'n') y += 3;
    }
  }
  if (x == y) {
    cout << "Draw";
  } else if (x > y) {
    cout << "White";
  } else {
    cout << "Black";
  }
  return 0;
}
