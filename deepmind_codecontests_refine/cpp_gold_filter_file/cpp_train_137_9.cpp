#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long k;
  cin >> k;
  string s;
  cin >> s;
  long long n = s.size();
  long long a[26] = {0};
  for (long long i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  for (long long i = 0; i < 26; i++) {
    if (a[i] % k != 0) {
      cout << -1;
      return 0;
    }
  }
  string ans = "";
  for (long long i = 0; i < 26; i++) {
    for (long long j = 0; j < a[i] / k; j++) {
      ans += (i + 'a');
    }
  }
  string p = ans;
  for (long long i = 0; i < k - 1; i++) {
    ans += p;
  }
  cout << ans;
  return 0;
}
