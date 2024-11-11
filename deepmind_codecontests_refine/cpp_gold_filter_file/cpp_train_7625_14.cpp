#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str1, str2;
    cin >> str1;
    int sz = str1.size();
    int s = 0, r = 0, p = 0;
    for (int i = 0; i < sz; ++i) {
      if (str1[i] == 'S')
        s++;
      else if (str1[i] == 'P')
        p++;
      else
        r++;
    }
    if (s >= r && s >= p) {
      for (int i = 0; i < sz; ++i) str2 += 'R';
    } else if (r >= p && r >= s) {
      for (int i = 0; i < sz; ++i) str2 += 'P';
    } else {
      for (int i = 0; i < sz; ++i) str2 += 'S';
    }
    cout << str2 << "\n";
  }
  return 0;
}
