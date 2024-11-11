#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, i, j;
  string s;
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> s;
    l = s.size();
    cout << s[0];
    for (j = 1; j <= l - 2; j++) {
      cout << s[j];
    }
    cout << s[l - 1] << endl;
  }
  return 0;
}
