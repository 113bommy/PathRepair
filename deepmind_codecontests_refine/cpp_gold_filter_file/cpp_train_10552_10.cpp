#include <bits/stdc++.h>
using namespace std;
string t, str;
int main() {
  int i, j, k, l, m, n, anslen = 0;
  string s;
  cin >> s;
  n = s.size();
  l = n - 1;
  map<string, int> mp;
  map<string, int>::iterator it;
  for (i = n; i >= 0; i--) {
    for (j = 0; j <= n - i; j++) {
      t = "";
      for (k = j; k < j + i; k++) {
        t += s[k];
      }
      mp[t]++;
    }
  }
  for (it = mp.begin(); it != mp.end(); it++) {
    if (it->second >= 2) {
      str = it->first;
      int LEN = str.size();
      anslen = max(anslen, LEN);
    }
  }
  cout << anslen << endl;
}
