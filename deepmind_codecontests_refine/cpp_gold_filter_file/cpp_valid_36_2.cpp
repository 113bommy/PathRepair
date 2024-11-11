#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long maxn = 1e5 + 5;
void solve() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << "a"
         << "\n";
  else if (n == 2)
    cout << "bc"
         << "\n";
  else if (n == 3)
    cout << "abc"
         << "\n";
  else {
    string a(n / 2, 'a');
    string b(n / 2 - 1, 'a');
    if (n & 1)
      cout << a << "bc" << b << "\n";
    else
      cout << a << "b" << b << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  ;
  long long T;
  cin >> T;
  while (T--) solve();
}
