#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long a[10][N] = {};
void solve() {
  long long n, m = 0, i = 0, j = 0, l, r, k = 0, p = 1, x, y, b[200005];
  cin >> n;
  while (n % 2 == 0) n /= 2, i++;
  while (n % 3 == 0) n /= 3, j++;
  if (i > j)
    cout << "-1\n";
  else {
    cout << 2 * j - i << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
