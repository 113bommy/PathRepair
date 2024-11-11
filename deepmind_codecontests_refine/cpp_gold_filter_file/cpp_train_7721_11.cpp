#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  string s[n];
  for (long long i = 0; i < n; i++) cin >> s[i];
  long long a[m];
  for (long long i = 0; i < m; i++) cin >> a[i];
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    unordered_map<char, long long> mp;
    for (long long j = 0; j < n; j++) {
      mp[s[j][i]]++;
    }
    long long maxx = -1;
    for (long long i = 'A'; i <= 'E'; i++) {
      if (mp[i] > maxx) maxx = mp[i];
    }
    ans += (maxx * a[i]);
  }
  cout << ans << endl;
  return 0;
}
