#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; s[i] != '\0'; ++i)
    if (s[i] >= 'A' && s[i] <= 'Z') cnt++;
  if (cnt == s.length() || (cnt == s.length() && islower(s[0]))) {
    for (int i = 0; s[i] != '\0'; ++i) {
      if (s[i] >= 'a' && s[i] <= 'z')
        s[i] -= ('a' - 'A');
      else
        s[i] += ('a' - 'A');
    }
  }
  cout << s;
}
