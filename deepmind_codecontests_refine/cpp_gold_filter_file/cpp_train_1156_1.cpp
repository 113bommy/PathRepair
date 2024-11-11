#include <bits/stdc++.h>
using namespace std;
int i, n, s, f;
void solve() {
  cin >> n;
  while (int(sqrt(n)) == sqrt(n) && n > 1) n = sqrt(n), s++;
  for (i = sqrt(n); i > 1; i--)
    while (n % (i * i) == 0) s++, f = 1, n /= i;
  cout << n << " " << s + f;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
