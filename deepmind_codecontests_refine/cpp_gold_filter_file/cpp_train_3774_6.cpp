#include <bits/stdc++.h>
using namespace std;
long long int const inf = 1e18;
long long int const maxn = 1e6 + 5;
long long int const mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    string ans("-1");
    if (n == 1) ans = arr[0];
    for (long long int i = 0; i < m; i++) {
      set<char> can;
      long long int flag = 0;
      for (long long int j = 1; j < n; j++) {
        long long int cnt = 0;
        for (long long int k = 0; k < m; k++) {
          if (k == i) continue;
          if (arr[j][k] != arr[0][k]) cnt++;
        }
        if (cnt >= 2) {
          flag = 1;
          break;
        }
        if (cnt == 1) can.insert(arr[j][i]);
      }
      if (flag) continue;
      long long int sz = can.size();
      if (sz > 1) continue;
      if (sz == 0) ans = arr[0];
      if (sz == 1) {
        arr[0][i] = *can.begin();
        ans = arr[0];
      }
    }
    cout << ans << "\n";
    ;
  }
  return 0;
}
