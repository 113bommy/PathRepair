#include <bits/stdc++.h>
using namespace std;
int main() {
  int q[3222];
  string s;
  cin >> s;
  int p = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    q[s[i] - 'a']++;
  }
  for (int i = 0; i < 30; i++) {
    if (q[i] % 2 != 0) {
      p++;
    }
  }
  if (p % 2 != 0 || p == 0) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
