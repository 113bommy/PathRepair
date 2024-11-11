#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s, t;
  cin >> s;
  map<char, long long> m;
  long long c0 = 0;
  for (int i = 0; i < (long long)s.size(); i++) {
    m[s[i]]++;
    if (s[i] == '0') c0++;
    if ((s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9') &&
            m[s[i]] == 1 ||
        s[i] == '0')
      continue;
    t.push_back(s[i]);
  }
  for (int i = 0; i < 4; i++) t.push_back('0');
  long long mod = 0, dig;
  for (int i = 0; i < (long long)t.size(); i++) {
    dig = t[i] - '0';
    mod = mod * 10 + dig;
    mod = mod % 7;
  }
  for (int i = 0; i < 4; i++) t.erase(t.begin() + (long long)t.size() - 1);
  string rem[7];
  rem[0] = "1869";
  rem[1] = "1968";
  rem[2] = "1689";
  rem[3] = "6189";
  rem[4] = "1698";
  rem[5] = "1986";
  rem[6] = "1896";
  if ((long long)t.size()) cout << t;
  cout << rem[(7 - mod) % 7];
  while (c0--) cout << c0;
  cout << "\n";
  return 0;
}
