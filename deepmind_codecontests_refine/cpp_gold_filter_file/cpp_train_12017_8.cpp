#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int a = 0, b = 0, c = 0;
  int i;
  for (i = 0; s[i] != '+'; i++) a++;
  for (i++; s[i] != '='; i++) b++;
  for (i++; i < s.size(); i++) c++;
  if (a + b == c)
    cout << s << endl;
  else if (c > 1 && a + b == c - 2) {
    for (i = 0; i < a + 1; i++) printf("|");
    printf("+");
    for (i = 0; i < b; i++) printf("|");
    printf("=");
    for (i = 0; i < c - 1; i++) printf("|");
  } else if ((a > 1 || b > 1) && a + b == c + 2) {
    if (a > 1) {
      for (i = 0; i < a - 1; i++) printf("|");
      printf("+");
      for (i = 0; i < b; i++) printf("|");
      printf("=");
      for (i = 0; i < c + 1; i++) printf("|");
    } else {
      for (i = 0; i < a; i++) printf("|");
      printf("+");
      for (i = 0; i < b - 1; i++) printf("|");
      printf("=");
      for (i = 0; i < c + 1; i++) printf("|");
    }
  } else
    printf("Impossible");
  return 0;
}
