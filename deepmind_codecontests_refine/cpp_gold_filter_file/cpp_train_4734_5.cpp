#include <bits/stdc++.h>
using namespace std;
int main() {
  char b[] = "aeiuoy";
  char s[200];
  gets(s);
  int i;
  int n = strlen(s);
  for (i = n - 1; i >= 0; i--) {
    if (isalpha(s[i])) {
      break;
    }
  }
  char c = tolower(s[i]);
  for (i = 0; i < 6; i++) {
    if (c == b[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
