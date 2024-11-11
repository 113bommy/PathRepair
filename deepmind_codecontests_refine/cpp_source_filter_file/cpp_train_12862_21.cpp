#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> v;
  bool result = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if ((result == false) && (s[0] == '0' && s[1] == '0')) {
      s[0] = '+';
      s[1] = '+';
      result = true;
    }
    if ((result == false) && (s[3] == '0' && s[4] == '0')) {
      s[3] = '+';
      s[4] = '+';
      result = true;
    }
    v.push_back(s);
  }
  if (result) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
