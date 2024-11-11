#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int ans = 1;
    if (b >= a) {
      ans += (a * (a - 1)) / 2;
    } else {
      ans = (b * (b + 1)) / 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
