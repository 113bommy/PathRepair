#include <bits/stdc++.h>
using namespace std;
void y() { cout << "YES" << endl; }
void n() { cout << "NO" << endl; }
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b == c && a % 2 == 0)
    y();
  else if (a == c && b % 2 == 0)
    y();
  else if (a == b && c % 2 == 0)
    y();
  else if (a >= (b + c) || b >= (a + c) || c >= (a + b))
    y();
  else
    n();
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
