#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool found = false;
  for (int len = 1; len <= s.length() / 4; len++) {
    for (int start = 0; start + 4 * len < s.length(); start++) {
      bool poss = true;
      for (int kk = 0; kk <= 4; kk++) {
        if (s[start + len * kk] != '*') {
          poss = false;
        }
      }
      if (poss) {
        found = true;
      }
    }
  }
  if (found) {
    printf("yes");
  } else {
    printf("no");
  }
  return 0;
}
