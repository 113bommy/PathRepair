#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n;
  cin >> m;
  long long int val = min(n - 1, m);
  val = (val * (val + 1)) / 2;
  val += ((m > n) ? 1 : 0);
  cout << val;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
