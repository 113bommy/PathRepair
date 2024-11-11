#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string* s = new string[n];
  for (int i = 0; i < n; i++) {
    string a, b;
    string s2;
    cin >> s2;
    a = s2.at(0);
    b = s2.at(s2.length() - 1);
    if (s2.length() >= 11) {
      s[i] = a + to_string(s2.length() - 2) + b;
    } else {
      s[i] = s2;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}
