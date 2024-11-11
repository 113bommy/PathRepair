#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20];
int main() {
  gets(buf);
  string s(buf);
  for (int i = s.size() - 1;; i--)
    if (isupper(s[i]) || islower(s[i])) {
      char x = s[i];
      if (islower(x)) x -= 'a' - 'A';
      if (x == 'A' || x == 'E' || x == 'O' || x == 'I' || x == 'Y' || x == 'U')
        puts("YES");
      else
        puts("NO");
      return 0;
    }
  return 0;
}
