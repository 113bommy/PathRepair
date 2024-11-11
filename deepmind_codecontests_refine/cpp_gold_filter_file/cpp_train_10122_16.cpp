#include <bits/stdc++.h>
using namespace std;
long long int n, m, a, b;
void solve() {
  cin >> a >> b;
  if (a == b)
    cout << 0 << endl;
  else if (a < b) {
    if ((b - a) % 2 == 0)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  } else {
    if ((a - b) % 2 == 0)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}
