#include <bits/stdc++.h>
using namespace std;
string s;
char c, a[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
int main() {
  getline(cin, s);
  int n = s.size();
  for (int i = n; i > 0; i--) {
    if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
      c = s[i];
      break;
    }
  }
  for (int i = 0; i < 12; i++) {
    if (c == a[i]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
