#include <bits/stdc++.h>
using namespace std;
long long k;
string s, b;
long long pow29[1505], pow31[1505];
long long hash29[1505][1505], hash31[1505][1505], pref[1505];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> b >> k;
  long long n = s.length();
  pow29[0] = pow31[0] = 1;
  for (long long i = 1; i < 1505; i++) {
    pow29[i] = (pow29[i - 1] * 29) % (1000000007);
    pow31[i] = (pow31[i - 1] * 31) % (1000000007);
  }
  for (long long i = 0; i < n; i++)
    for (long long j = i; j < n; j++) {
      if (i == j) {
        hash29[i][j] = s[j] - 'a' + 1;
        hash31[i][j] = s[j] - 'a' + 1;
      } else {
        hash29[i][j] = (hash29[i][j - 1] + (s[j] - 'a' + 1) * (pow29[j - i])) %
                       (1000000007);
        hash31[i][j] = (hash31[i][j - 1] + (s[j] - 'a' + 1) * (pow31[j - i])) %
                       (1000000007);
      }
    }
  pref[0] = (b[s[0] - 'a'] - '0') ^ 1;
  for (long long i = 1; i < n; i++)
    pref[i] = pref[i - 1] + ((b[s[i] - 'a'] - '0') ^ 1);
  set<pair<long long, long long>> st;
  long long ans = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = i; j < n; j++) {
      if ((pref[j] - pref[i] + ((b[s[i] - 'a'] - '0') ^ 1)) <= k) {
        if (st.find({hash29[i][j], hash31[i][j]}) != st.end()) continue;
        st.insert({hash29[i][j], hash31[i][j]});
        ans++;
      }
    }
  cout << ans << "\n";
}
