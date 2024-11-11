#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  n--;
  long long res = sqrt(4 * n + 1) - 1;
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
