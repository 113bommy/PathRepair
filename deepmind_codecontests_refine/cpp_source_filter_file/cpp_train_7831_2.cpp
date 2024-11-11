#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j, k, p, c, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = s.length();
    long long int one = 0, zero = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    if (one == 0 || zero == 0)
      cout << s << "\n";
    else {
      p = max(one, zero);
      string str;
      for (i = 1; i <= p; i++) str += "10";
      cout << str << "\n";
    }
  }
  return 0;
}
