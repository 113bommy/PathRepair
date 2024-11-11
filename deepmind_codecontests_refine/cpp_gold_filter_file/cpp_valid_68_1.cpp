#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k, a = 1, b = 2;
  cin >> k;
  if (k == 1) {
    cout << 1 << " " << 1 << '\n';
    return;
  }
  while (b * b < k) {
    a++;
    b++;
  }
  long long diff = b * b - a * a;
  if (k - a * a < diff / 2 + 1)
    cout << k - a * a << " " << a + 1 << '\n';
  else if (k - a * a > diff / 2 + 1)
    cout << a + 1 << " " << diff - (k - a * a) + 1 << '\n';
  else
    cout << a + 1 << " " << a + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
