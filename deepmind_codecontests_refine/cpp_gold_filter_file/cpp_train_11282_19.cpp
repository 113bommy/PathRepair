#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int j = 1;
  for (int i = 0, n = t.length(); i < n; i++) {
    if (t[i] == s[j - 1]) {
      if (j < s.length()) j++;
    }
  }
  cout << j;
}
