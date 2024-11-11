#include <bits/stdc++.h>
const long long int mod = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << "0" << endl;
      continue;
    }
    int ans = 0;
    bool max_reached = false;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1] && !max_reached) continue;
      if (!max_reached) {
        max_reached = true;
        continue;
      }
      if (a[i] > a[i + 1] && max_reached) {
        ans = i + 1;
        break;
      }
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
