#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n;
  cin >> n;
  long long int a[n];
  map<long long int, long long int> mp;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  long long int prev = mp[1];
  long long int mx = 1;
  for (long long int i = 2; i <= n; i++) {
    if (mp[i] > mp[i - 1]) {
      long long int j = i;
      long long int cnt = 1;
      while (mp[j] > mp[j - 1]) {
        cnt++;
        j++;
      }
      mx = max(mx, cnt);
      i = j - 1;
    }
  }
  long long int ans = n - mx;
  cout << ans << "\n";
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
