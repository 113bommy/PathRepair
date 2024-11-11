#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> bal(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1')
      bal[i] = bal[i + 1] + 1;
    else
      bal[i] = min(bal[i + 1] - 1, 0);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (bal[i + 1] >= 0) s[i] = '0';
    }
  }
  cout << s;
}
