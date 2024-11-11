#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, p, b, c = 0, d, m, n, k, x, y, sum = 0, flag = 1;
  cin >> n >> p >> k;
  if (p - k > 1) cout << "<<";
  for (i = p - k; i < p; i++) {
    if (i > 0) cout << i << " ";
  }
  if (i == p) cout << "(" << p << ") ";
  for (i = p + 1; i < p + k + 1; i++)
    if (i <= n) cout << i << " ";
  if (p + k < n) cout << ">>";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
