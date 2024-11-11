#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
long long c, ans, x[26];
string s;
map<pair<char, long long>, long long> m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 26; i++) cin >> x[i];
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    ans += m[{s[i], c - x[s[i] - 'a']}];
    m[{s[i], c}]++;
    c += x[s[i] - 'a'];
  }
  cout << ans << endl;
  return 0;
}
