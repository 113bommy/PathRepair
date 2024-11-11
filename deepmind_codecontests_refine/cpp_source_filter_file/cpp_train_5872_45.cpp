#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  scanf("%d%d", &n, &x);
  if (n == 5) {
    cout << ">...v" << endl
         << "v.<.." << endl
         << "..^.." << endl
         << ">...." << endl
         << "..^.<" << endl
         << 1 << " " << 1 << endl;
    return 0;
  }
  if (n == 3) {
    cout << ">vv" << endl
         << "^<." << endl
         << "^.<" << endl
         << 1 << " " << 3 << endl;
    return 0;
  }
  for (int i = 1; i <= 100; i++) {
    if (i == 1)
      putchar('>');
    else
      putchar('^');
    if (i % 2 == 1) {
      for (int j = 2; j <= 33; j++) putchar('>');
      for (int j = 33; j <= 99; j++)
        if (j % 2 == 0)
          putchar('>');
        else
          putchar('.');
      putchar('v');
      cout << endl;
      continue;
    }
    if (i == 100)
      putchar('.');
    else
      putchar('v');
    for (int j = 3; j <= 67; j++)
      if (j % 2 == 0)
        putchar('<');
      else
        putchar('.');
    for (int j = 68; j <= 100; j++) putchar('<');
    cout << endl;
  }
  cout << 1 << " " << 1 << endl;
  return 0;
}
