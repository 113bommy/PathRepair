#include <bits/stdc++.h>
using namespace std;
long long i, n, r, a, q;
void solve() {
  cin >> n;
  if (n == 4 || n == 1 || n == 2) {
    cout << "-1\n";
    return;
  }
  a = n / 3;
  r = n % 3;
  if (r == 1) {
    cout << n / 3 - 2 << " 0 "
         << "1\n";
    return;
  }
  if (r == 2) {
    cout << n / 3 - 1 << " 1 0"
         << "\n";
    return;
  }
  cout << n / 3 << " 0"
       << " 0"
       << "\n";
}
int main() {
  for (cin >> q; q--;) {
    solve();
  }
}
