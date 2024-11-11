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
    if ((result == false) && (s[0] == 'O' && s[1] == 'O')) {
      s[0] = '+';
      s[1] = '+';
      result = true;
    }
    if ((result == false) && (s[3] == 'O' && s[4] == 'O')) {
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
