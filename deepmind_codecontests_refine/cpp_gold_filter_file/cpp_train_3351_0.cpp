#include <bits/stdc++.h>
using namespace std;
bool posible(string s, string x) {
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (s[i] == x[j]) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s, x;
    cin >> s >> x;
    if (posible(s, x)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
