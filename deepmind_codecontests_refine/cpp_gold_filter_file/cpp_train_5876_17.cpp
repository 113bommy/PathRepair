#include <bits/stdc++.h>
using namespace std;
string s1, s2;
signed main() {
  bool check = true;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[s1.size() - i - 1]) {
      check = false;
    }
  }
  if (check == true) {
    cout << "YES" << '\n';
  } else
    cout << "NO" << '\n';
}
