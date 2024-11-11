#include <bits/stdc++.h>
using namespace std;
long long p;
map<long long, int> m[123];
int main() {
  int characters_value[26], i;
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
