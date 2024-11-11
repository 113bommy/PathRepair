#include <bits/stdc++.h>
using namespace std;
char down(char c) {
  if (c >= 'A' && c <= 'Z') c += 32;
  return c;
}
char up(char c) {
  if (c >= 'a' && c <= 'z') c -= 32;
  return c;
}
int main() {
  char a[50], c, d[50];
  int b, i, j, k;
  while (cin >> a >> b) {
    for (i = 0; i < strlen(a); i++) {
      c = down(a[i]);
      if (c < 'a' - 1 + b) {
        d[i] = up(c);
      } else {
        d[i] = down(c);
      }
    }
    d[i] = '\0';
    cout << d << endl;
  }
  return 0;
}
