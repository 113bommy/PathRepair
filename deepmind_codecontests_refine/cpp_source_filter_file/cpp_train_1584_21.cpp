#include <bits/stdc++.h>
using namespace std;
const long long zero = 0;
const double PI = 3.14159265358979323846;
void solve() {
  long long n, m;
  string s;
  cin >> n;
  long long a, b;
  if (n % 2 == 0) {
    b = 2;
    a = b + n;
  } else {
    b = 9;
    a = b + n;
  }
  cout << a << " " << b;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
