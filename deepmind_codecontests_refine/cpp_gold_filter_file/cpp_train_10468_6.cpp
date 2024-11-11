#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[3];
  cin >> s;
  int now = 8;
  if ((s[0] == 'a' || s[0] == 'h') && (s[1] == '1' || s[1] == '8')) {
    now = 3;
  } else if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8') {
    now = 5;
  } else
    now = 8;
  printf("%d\n", now);
  return 0;
}
