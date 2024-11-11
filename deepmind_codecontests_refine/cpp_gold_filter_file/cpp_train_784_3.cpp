#include <bits/stdc++.h>
using namespace std;
int x, y, f, l, mas[30], k;
char a[30][30];
string st;
int main() {
  cin >> st;
  for (int i = 0; i < 27; ++i) {
    int p = st[i] - 'A';
    if (!mas[p])
      mas[p] = i + 1;
    else {
      x = mas[p] - 1;
      y = i;
      break;
    }
  }
  if (y - x == 1) {
    cout << "Impossible";
    return 0;
  } else {
    int p = (y - x) / 2;
    if ((y - x) % 2) {
      a[2][(y - x) / 2 + 1] = st[x];
      k = x + 1;
    } else
      k = x;
    f = 2;
    l = (y - x) / 2;
    for (int i = 0; i < y - x - (y - x) % 2; ++i) {
      a[f][l] = st[k];
      if (f == 2) {
        --l;
        if (l < 1) {
          f = 1;
          l = 1;
        }
      } else
        ++l;
      ++k;
    }
    for (int i = x - 1; i >= 0; --i) {
      a[f][l] = st[i];
      if (f == 1) {
        ++l;
        if (l > 13) {
          f = 2;
          l = 13;
        }
      } else
        --l;
    }
    for (int i = 26; i > y; --i) {
      a[f][l] = st[i];
      if (f == 1) {
        ++l;
        if (l > 13) {
          f = 2;
          l = 13;
        }
      } else
        --l;
    }
  }
  for (int i = 1; i < 3; ++i) {
    for (int j = 1; j < 14; ++j) cout << a[i][j];
    cout << endl;
  }
}
