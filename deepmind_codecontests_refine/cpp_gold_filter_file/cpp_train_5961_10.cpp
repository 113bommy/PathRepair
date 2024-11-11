#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = acos((ld)-1.0);
const double eps = (double)1e-9;
const int inf = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  cout << (n + 1) * 3 + 1 << endl;
  for (int i = 0; i <= n; i++) {
    cout << i << ' ' << i << endl;
    cout << i + 1 << ' ' << i << endl;
    cout << i << ' ' << i + 1 << endl;
  }
  cout << n + 1 << ' ' << n + 1 << endl;
  return 0;
}
const int fastio = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
