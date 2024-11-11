#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int i = 1;
  int k = 0;
  for (i = 2; i <= n + 1; i++) {
    k = (int)(pow(2, i) + .5) - 1;
    if (n % k == 0) break;
  }
  cout << n / k << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
