#include <bits/stdc++.h>
using namespace std;
int main() {
  char s, t;
  int a, b;
  char temp[3];
  cin >> temp;
  s = temp[0];
  a = temp[1] - '0';
  cin >> temp;
  t = temp[0];
  b = temp[1] - '0';
  int l, c;
  int nr = 0, v[7] = {0};
  while (s != t || a != b) {
    l = (a - b < 0) ? -1 : ((a - b > 0) ? 1 : 0);
    c = (s - t < 0) ? 1 : ((s - t > 0) ? -1 : 0);
    if (l == 0 && c == 0) {
      break;
    }
    if (l * c != 0) {
      if (l == -1 && c == -1) v[nr++] = 1, s--, a++;
      if (l == -1 && c == 1) v[nr++] = 3, s++, a++;
      if (l == 1 && c == 1) v[nr++] = 5, s++, a--;
      if (l == 1 && c == -1) v[nr++] = 7, s--, a--;
      continue;
    }
    if (l == 0 && c == -1) v[nr++] = 8, s--;
    if (l == 0 && c == 1) v[nr++] = 4, s++;
    if (l == -1 && c == 0) v[nr++] = 2, a++;
    if (l == 1 && c == 0) v[nr++] = 6, a--;
  }
  cout << nr << endl;
  for (int i = 0; i < nr; i++) {
    switch (v[i]) {
      case 1:
        cout << "LU" << endl;
        break;
      case 2:
        cout << "U" << endl;
        break;
      case 3:
        cout << "RU" << endl;
        break;
      case 4:
        cout << "R" << endl;
        break;
      case 5:
        cout << "RD" << endl;
        break;
      case 6:
        cout << "D" << endl;
        break;
      case 7:
        cout << "LD" << endl;
        break;
      case 8:
        cout << "L" << endl;
        break;
    }
  }
  return 0;
}
