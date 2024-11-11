#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long inf = 1e18;
const char nl = '\n';
void solve_it() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (!(n & 1) && !(k & 1) && n >= k * k)
      cout << "YES" << nl;
    else if ((n & 1) && (k & 1) && n >= k * k)
      cout << "YES" << nl;
    else
      cout << "NO" << nl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve_it();
  return 0;
}
