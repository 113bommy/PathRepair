#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100], b[199], c[100];
  int i, j, x, y;
  gets(a);
  gets(b);
  x = strlen(a);
  y = strlen(b);
  for (i = y - 1; i >= 0; i--) {
    c[y - i - 1] = b[i];
  }
  c[y] = '\0';
  if (strcmp(a, c) == 0) {
    cout << "YES" << endl;
    return 0;
  } else {
    cout << "NO" << endl;
    return 0;
  }
  return 0;
}
