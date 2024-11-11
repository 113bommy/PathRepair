#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  int c = 0;
  vector<int> v;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      c++;
      v.push_back(i);
    }
  }
  if (c % 2 != 0) {
    cout << "impossible";
  } else {
    for (int i = 0; i < c / 2; i++) {
      if (s[v[i]] == '0')
        s[v[i]] = '1';
      else if (s[v[i]] == '1')
        s[v[i]] = '0';
    }
    cout << s;
  }
  return 0;
}
