#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> v(n);
    long long int tot = 0;
    for (long long int i = 0; i < n; i++) tot += (s[i] == '1');
    long long int ans = tot;
    for (long long int i = 0; i < n - k + 1; i++) {
      long long int d = 0;
      for (long long int j = i; j < n; j += k) {
        if (s[i] == '1')
          d++;
        else
          d--;
        d = max(d, (long long)0);
        ans = min(ans, tot - d);
      }
    }
    cout << ans << endl;
  }
}
