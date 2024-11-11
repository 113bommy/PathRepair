#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, com = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (i <= s.length() - 3) {
      if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') {
        i += 2;
        com++;
        continue;
      }
      if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B') {
        a++;
        i += 2;
        continue;
      }
    }
    if (s[i] == 'A' && s[i + 1] == 'B') a++;
    if (s[i] == 'B' && s[i + 1] == 'A') b++;
  }
  if (com >= 2) {
    puts("YES");
  } else if (com == 1 && (a >= 1 || b >= 1)) {
    puts("YES");
  } else if (a >= 1 && b >= 1) {
    puts("YES");
  } else
    puts("NO");
  return 0;
}
