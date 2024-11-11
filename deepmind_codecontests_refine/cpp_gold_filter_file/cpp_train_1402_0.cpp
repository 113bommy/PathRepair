#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL g_l, g_r;
LL gcd(LL a, LL b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool input() {
  cin >> g_l >> g_r;
  if (cin.eof()) return false;
  return true;
}
void solve() {
  for (LL i = g_l; i <= g_r; ++i) {
    for (LL j = i + 1; j <= g_r; ++j) {
      for (LL k = j + 1; k <= g_r; ++k) {
        if (gcd(i, k) != 1 && gcd(i, j) == 1 && gcd(j, k) == 1) {
          cout << i << " " << j << " " << k << endl;
          return;
        }
      }
    }
  }
  cout << -1 << endl;
}
int main() {
  while (input()) {
    solve();
  }
  return 0;
}
