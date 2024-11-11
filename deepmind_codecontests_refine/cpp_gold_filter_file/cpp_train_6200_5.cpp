#include <bits/stdc++.h>
using namespace std;
void inout() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  inout();
  long long int n, i;
  cin >> n;
  long long int a[n];
  map<long long int, long long int> mp;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  long long int ans = 0;
  for (auto j : mp) {
    for (long long int x = 0; x <= 31; x++) {
      if (pow(2LL, x) - j.first > j.first) {
        long long int z = pow(2LL, x) - j.first;
        if (mp.find(z) != mp.end()) {
          ans += (mp[z] * mp[j.first]);
        }
      } else if (pow(2LL, x) - j.first == j.first) {
        long long int z = pow(2LL, x) - j.first;
        if (mp.find(z) != mp.end()) {
          ans += ((mp[z] - 1) * (mp[z]) / 2);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
