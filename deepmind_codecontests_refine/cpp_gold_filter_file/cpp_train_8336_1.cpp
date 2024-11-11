#include <bits/stdc++.h>
using namespace std;
const long long int maxm = 1e9 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    bool fl = 0;
    for (int j = 0; j <= 31; j++) {
      long long x = (1 << j) - a[i];
      if (mp.count(x) && (mp[x] > 1 || (mp[x] == 1 && x != a[i]))) fl = 1;
    }
    if (fl == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
