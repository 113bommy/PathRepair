#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string c = "a";
  string sf = "";
  for (int i = s.size() - 1; i > 0; i--) {
    if (c[0] - s[i] <= 0) {
      c = s[i];
      sf.insert(0, c);
    }
  }
  cout << sf;
  return 0;
}
