#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 2;
  int p;
  int m = 0;
  p = 0;
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < (int)s.size(); i++) {
    mp[s[i]]++;
  }
  for (int i = 0; i < (int)s.length(); i++) {
    if ((mp[i]) % 2 != 0) {
      p++;
    }
  }
  if (p % 2 != 0 || p == 0) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
