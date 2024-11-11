#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x = 1;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[i] == s[i + 1]) x = 0;
    }
  }
  if (x == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
