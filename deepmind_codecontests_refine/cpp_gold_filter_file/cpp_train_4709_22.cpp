#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[101];
  int b;
  char c[101];
  int k = 0;
  cin >> a;
  b = strlen(a);
  strcpy(c, a);
  for (int i = 0; i < b; i++) {
    if (i == 0) {
      if ((int)a[i] >= 97 && (int)a[i] <= 122)
        a[i] = char((int)a[i] - 32);
      else
        a[i] = char((int)a[i] + 32);
    } else {
      if ((int)a[i] >= 65 && (int)a[i] <= 90)
        a[i] = char((int)a[i] + 32);
      else {
        k = 1;
        break;
      }
    }
  }
  if (k == 0)
    cout << a;
  else
    cout << c;
}
