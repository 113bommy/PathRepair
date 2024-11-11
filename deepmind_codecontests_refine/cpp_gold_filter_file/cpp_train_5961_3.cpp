#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long x = 0, y = 0;
  cout << 8 * (n + 1) - n << endl;
  cout << x << " " << y << endl;
  cout << x + 1 << " " << y << endl;
  cout << x + 2 << " " << y << endl;
  cout << x << " " << y + 1 << endl;
  cout << x << " " << y + 2 << endl;
  cout << x + 1 << " " << y + 2 << endl;
  cout << x + 2 << " " << y + 1 << endl;
  cout << x + 2 << " " << y + 2 << endl;
  x += 2;
  y += 2;
  for (long long i = 1; i <= n; i++) {
    cout << x + 1 << " " << y << endl;
    cout << x + 2 << " " << y << endl;
    cout << x << " " << y + 1 << endl;
    cout << x << " " << y + 2 << endl;
    cout << x + 1 << " " << y + 2 << endl;
    cout << x + 2 << " " << y + 1 << endl;
    cout << x + 2 << " " << y + 2 << endl;
    x += 2;
    y += 2;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
