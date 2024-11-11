#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int len = s.length();
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] != 'z') {
      s[i]++;
      break;
    } else {
      s[i] = 'a';
    }
  }
  if (s >= t)
    puts("No such string");
  else
    cout << s << endl;
  return 0;
}
