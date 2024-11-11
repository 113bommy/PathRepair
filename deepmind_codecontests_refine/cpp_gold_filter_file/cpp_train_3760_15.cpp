#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int mod = 998244353;
int main() {
  int n, l = 0, r = 1e9;
  cin >> n;
  cout << "0 1" << endl;
  string st, s;
  cin >> st;
  for (int i = 1; i <= n - 1; i++) {
    int m = (l + r) / 2;
    cout << m << " " << 1 << endl;
    cin >> s;
    if (s == st)
      l = m;
    else
      r = m;
  }
  cout << l << " " << 0 << " " << r << " " << 2 << endl;
  return 0;
}
