#include <bits/stdc++.h>
using namespace std;
long long p;
map<long, int> m[123];
int main() {
  long long characters_value[26];
  long long i;
  for (i = 0; i < 26; i++) cin >> characters_value[i];
  string s;
  cin >> s;
  long long ans = 0;
  for (i = 0; i < s.size(); i++) {
    ans += m[s[i]][p];
    p += characters_value[s[i] - 'a'];
    m[s[i]][p]++;
  }
  cout << ans;
}
