#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> mp;
    for (i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;
    sort((a).begin(), (a).end());
    a.erase(unique((a).begin(), (a).end()), a.end());
    long long ans = 1;
    for (i = 0; i < a.size(); i++) {
      if (a[i] <= ans) {
        ans += mp[a[i]];
        continue;
      }
      long long tmp = ans;
      while (i < a.size() && tmp < a[i]) {
        tmp += mp[a[i]];
        if (tmp - 1 >= a[i]) {
          ans = tmp;
          break;
        }
        i++;
      }
    }
    cout << ans << "\n";
  }
}
