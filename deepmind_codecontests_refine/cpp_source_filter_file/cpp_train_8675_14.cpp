#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, w;
  char s[10];
  while (cin >> n) {
    scanf("%s", s), n--;
    if (!strcmp(s, "ULDR"))
      l = 2, w = 2;
    else if (!strcmp(s, "UL") || !strcmp(s, "DR"))
      l = 1, w = 2;
    else if (!strcmp(s, "UR") || !strcmp(s, "DL"))
      l = 2, w = 1;
    while (n--) {
      scanf("%s", s);
      if (!strcmp(s, "ULDR"))
        l++, w++;
      else if (!strcmp(s, "UL") || !strcmp(s, "DR"))
        w++;
      else if (!strcmp(s, "UR") || !strcmp(s, "DL"))
        l++;
    }
    cout << l * w << endl;
  }
  return 0;
}
