#include <bits/stdc++.h>
const double pie = 3.141592653589793238463;
using namespace std;
int main() {
  long long int t, i, j, k, l, m, n, x, y, z, c, d, e, p, nl, np, q, r;
  string s, str2, str3;
  long long int mx = INT_MIN;
  long long int mn = INT_MAX;
  long long int ans = 0, s1 = 0, s2 = 0;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    string st = "";
    for (int j = i; j < n; j++) {
      st += s[j];
      long long int f = 0;
      map<char, long long int> mp;
      long long int sz = st.size();
      for (k = 0; k < st.size(); k++) {
        mp[st[k]]++;
      }
      for (auto x : mp) {
        if (x.second <= (sz / 2)) {
          f = 1;
        } else {
          f = 0;
          break;
        }
      }
      if (f == 1) {
        cout << "YES"
             << "\n";
        cout << st << "\n";
        return 0;
      }
    }
  }
  cout << "NO"
       << "\n";
}
