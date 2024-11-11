#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    map<char, long long> mp;
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (long long i = 0; i < m; i++) {
      long long x;
      cin >> x;
      mp[x]++;
    }
    long long ans[200];
    memset(ans, 0, sizeof(ans));
    for (long long i = n; i >= 1; i--) {
      mp[i - 1] += mp[i];
      ans[s[i - 1]] += mp[i] + 1;
    }
    for (long long i = 'a'; i <= 'z'; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
