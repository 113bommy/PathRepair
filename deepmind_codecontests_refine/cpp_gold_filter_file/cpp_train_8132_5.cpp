#include <bits/stdc++.h>
using namespace std;
long long n, k, x;
int main() {
  if (0) {
    freopen("CP.inp", "r", stdin);
    freopen("CP.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> k >> x;
    cout << 9 * (k - 1) + x << '\n';
  }
  return 0;
}
