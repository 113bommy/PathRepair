#include <bits/stdc++.h>
using namespace std;
void doit() {
  long long k;
  cin >> k;
  string s;
  cin >> s;
  long long n = (long long)s.size();
  unordered_map<long long, long long> mp;
  mp[0] = 1;
  long long cur = 0;
  for (long long i = 0; i < n; i++) {
    cur += (s[i] == '1');
    mp[cur]++;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (k == 0) {
      ans += (mp[cur] * (mp[cur] - 1)) / 2;
    } else {
      ans += mp[i] * mp[i + k];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    doit();
  }
}
