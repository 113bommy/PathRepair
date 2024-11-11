#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> ans(n, false);
  string sol;
  long long i = 0;
  while (i < s.length()) {
    if (s[i] == 'o') {
      long long j = i + 1;
      while (j + 1 < s.length() and s[j] == 'g' and s[j + 1] == 'o') {
        j += 2;
      }
      if (j == i + 1) {
        ans.push_back(i);
        sol += s[i];
        i = j + 1;
      } else {
        sol += "***";
        i = j;
      }
      continue;
    }
    sol += s[i];
    i++;
  }
  cout << sol << endl;
}
