#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7;
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long f[26] = {0}, cnt = 0, cnt2 = 0;
  for (long long i = 0; i < s.length(); i++) f[s[i] - 'a']++;
  for (long long i = 0; i < 26; i++) {
    if (f[i] > 0) {
      cnt++;
      if (f[i] == 1) cnt2++;
    }
  }
  if (cnt > 4)
    cout << "No";
  else {
    if ((cnt == 3) && (cnt2 > 1))
      cout << "No";
    else if ((cnt == 2) && (cnt2 > 0))
      cout << "No";
    else if (cnt == 1)
      cout << "No";
    else
      cout << "Yes";
  }
  return 0;
}
