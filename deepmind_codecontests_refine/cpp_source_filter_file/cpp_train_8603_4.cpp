#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  set<char> c;
  for (int i = 0; i < s.length(); i++) c.insert(s[i]);
  if (k > n) {
    cout << s;
    for (int i = 0; i < n - k; i++) cout << *c.begin();
  } else {
    s = s.substr(0, k);
    for (int i = k - 1; i >= 0; i--)
      if (s[i] == *c.rbegin())
        s[i] = *c.begin();
      else {
        s[i] = *c.lower_bound(s[i] + 1);
        break;
      }
    cout << s;
  }
}
