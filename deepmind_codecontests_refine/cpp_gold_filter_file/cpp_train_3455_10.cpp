#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int i = 0;
  if (s.size() == 1 && k > 0)
    s = "0";
  else {
    while (i < k) {
      if (i >= s.size()) break;
      if (i == 0) {
        if (s[i] != '1') {
          s[i] = '1';
        } else
          k++;
      } else {
        if (s[i] != '0') {
          s[i] = '0';
        } else
          k++;
      }
      i++;
    }
  }
  cout << s << endl;
  return 0;
}
