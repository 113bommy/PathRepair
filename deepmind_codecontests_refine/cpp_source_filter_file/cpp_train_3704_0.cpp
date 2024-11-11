#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char last;
  if (s[0] != 'a') {
    cout << "NO";
    return 0;
  }
  last = 'a';
  for (int i = 1; i < s.size(); i++) {
    if (s[i] > last + 1) {
      cout << "NO";
      break;
    }
    if (s[i] == last + 1) {
      last = s[i];
    }
  }
  cout << "YES";
}
