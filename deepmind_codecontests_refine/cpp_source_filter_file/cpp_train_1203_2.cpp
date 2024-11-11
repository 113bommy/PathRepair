#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  int b = 0;
  s = s + "A";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y') {
      cnt = max(cnt, i - b);
      b = i;
    }
  }
  cout << cnt << endl;
  return 0;
}
