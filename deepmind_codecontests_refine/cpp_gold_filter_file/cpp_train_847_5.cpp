#include <bits/stdc++.h>
using namespace std;
string print9(int j) {
  string q = "";
  for (int i = 0; i < 9; ++i) {
    q = (char)('0' + (j % 10)) + q;
    j /= 10;
  }
  return q;
}
int main() {
  long long a, b, m, mx;
  cin >> a >> b >> m;
  mx = 1;
  for (int i = 0; i < 9; ++i) mx = (mx * 10) % m;
  for (int i = 0; i <= min(a, m - 1); ++i) {
    int t = (mx * i) % m;
    int q = (t == 0) ? 0 : m - t;
    if (q > b) {
      cout << 1 << ' ' << print9(i) << endl;
      return 0;
    }
  }
  cout << 2 << endl;
  return 0;
}
