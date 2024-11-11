#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, s1;
  cin >> s >> s1;
  string s2;
  cin >> s2;
  map<char, char> m;
  for (long long i = 0; i < 26; i++) {
    m[s[i]] = s1[i];
  }
  string ans = "";
  long long cnt = 0;
  for (long long i = 0; i < s2.size(); i++) {
    if (s2[i] >= 48 && s2[i] <= 57) {
      ans += s2[i];
    } else if (isupper(s2[i])) {
      s2[i] += 32;
      char c = m[s2[i]];
      c -= 32;
      ans += c;
    } else if (islower(s2[i])) {
      ans += m[s2[i]];
    }
  }
  cout << ans << "\n";
}
