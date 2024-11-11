#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int base = sqrt(n);
  if (base * base == n) {
    cout << base << " " << 1 << endl;
    return;
  }
  n = n - base * base;
  if (n <= base + 1) {
    cout << n << " " << base + 1 << endl;
  } else
    cout << base + 1 << " " << (2 * (base + 1) - n) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
