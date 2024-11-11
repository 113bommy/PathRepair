#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt, mcnt = 0, i, j;
  string s, s1 = "pi";
  cin >> n;
  cin >> s;
  for (i = 0; s[i] != '\0'; i++) {
    cnt = 01;
    for (j = i + 2; s[j] != '\0'; j++) {
      if (s[i] == s[j] && s[i + 1] == s[j + 1]) cnt++;
    }
    if (cnt > mcnt) {
      mcnt = cnt;
      s1 = string(1, s[i]) + string(1, s[i + 1]);
    }
  }
  cout << s1;
}
