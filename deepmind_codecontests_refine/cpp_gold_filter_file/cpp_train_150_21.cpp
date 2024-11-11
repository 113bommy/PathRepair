#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  int count = 1;
  int len = 1;
  while (len < n) {
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + len < n && s[j] == s[j + len] && s[j] == '*') {
        j = j + len;
        count++;
      }
      if (count > 4) {
        cout << "yes" << endl;
        return 0;
      }
      count = 1;
    }
    len++;
  }
  cout << "no" << endl;
  return 0;
}
