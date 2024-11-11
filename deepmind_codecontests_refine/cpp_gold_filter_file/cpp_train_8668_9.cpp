#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, k;
    cin >> x >> y >> k;
    long long int ans = ((long double)k * (y + 1) - 1);
    ans = (ans + (x - 1) - 1) / (x - 1);
    cout << ans + k << endl;
  }
  return 0;
}
