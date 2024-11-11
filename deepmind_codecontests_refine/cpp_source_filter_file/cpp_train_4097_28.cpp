#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string s1;
  int k = 0, i, j;
  for (i = 25; i >= 0; i--) {
    for (j = k; j < s.length(); j++) {
      if (int(s[j]) == 97 + i) {
        cout << s[i];
        k = i;
      }
    }
  }
}
