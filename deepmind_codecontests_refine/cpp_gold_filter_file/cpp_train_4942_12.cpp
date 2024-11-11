#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n;
char a[int(1e5 + 100)], b[int(1e5 + 100)];
int f[int(1e5 + 100)], s[int(1e5 + 100)], fb[int(1e5 + 100)],
    lef[int(1e5 + 100)];
int d[int(1e5 + 100)];
bool t[int(1e5 + 100)];
int main() {
  scanf("%s", a + 1);
  int la = strlen(a + 1);
  scanf("%s", b + 1);
  int lb = strlen(b + 1);
  int j = 0;
  for (int i = (2), _b = (lb); i <= _b; i++) {
    while (j != 0 && b[j + 1] != b[i]) j = fb[j];
    if (b[j + 1] == b[i]) j++;
    fb[i] = j;
  }
  j = 0;
  for (int i = (1), _b = (la); i <= _b; i++) {
    while (j != 0 && b[j + 1] != a[i]) j = fb[j];
    if (b[j + 1] == a[i]) j++;
    if (j == lb) {
      t[i] = true;
      j = fb[j];
    }
  }
  memset(lef, -63, sizeof(lef));
  int def = lef[0];
  for (int i = (1), _b = (la); i <= _b; i++)
    if (t[i]) {
      lef[i] = i - lb;
    } else {
      lef[i] = lef[i - 1];
    }
  d[0] = 1;
  s[0] = 1;
  for (int i = (1), _b = (la); i <= _b; i++) {
    f[i] = (f[i] + f[i - 1]) % int(1e9 + 7);
    int x;
    if (lef[i] == def) {
      d[i] = (f[i] + 1) % int(1e9 + 7);
      s[i] = (s[i - 1] + d[i]) % int(1e9 + 7);
      continue;
    }
    x = lef[i];
    f[i] = (f[i] + s[x]) % int(1e9 + 7);
    d[i] = (f[i] + 1) % int(1e9 + 7);
    s[i] = (s[i - 1] + d[i]) % int(1e9 + 7);
  }
  cout << f[la] << endl;
}
