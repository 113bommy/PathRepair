#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[105];
  cin >> a;
  int p = 0, i = 0;
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] == 'D' && a[i + 1] == 'a' && a[i + 2] == 'n' && a[i + 3] == 'i' &&
        a[i + 4] == 'l') {
      p++;
      i = i + 5;
    } else if (a[i] == 'O' && a[i + 1] == 'l' && a[i + 2] == 'y' &&
               a[i + 3] == 'a') {
      p++;
      i = i + 4;
    } else if (a[i] == 'S' && a[i + 1] == 'l' && a[i + 2] == 'a' &&
               a[i + 3] == 'v' && a[i + 4] == 'a') {
      p++;
      i = i + 5;
    } else if (a[i] == 'A' && a[i + 1] == 'n' && a[i + 2] == 'n') {
      p++;
      i = i + 3;
    } else if (a[i] == 'N' && a[i + 1] == 'i' && a[i + 2] == 'k' &&
               a[i + 3] == 'i' && a[i + 4] == 't' && a[i + 5] == 'a') {
      p++;
      i = i + 6;
    }
  }
  if (p == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
