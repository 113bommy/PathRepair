#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  string s;
  string a = "";
  cin >> n >> t;
  cin >> s;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < s.length() - 1; j++) {
      if (s[j] == 'B' && s[j + 1] == 'G') {
        s[j] = 'G';
        s[j + 1] = 'B';
        j = j + 2;
      }
    }
  }
  cout << s << endl;
  return 0;
}
