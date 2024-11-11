#include <bits/stdc++.h>
using namespace std;
char a[110000], b[110000];
char c[110000];
char getc(char x, char y) {
  char t = 'a';
  while (t == x || t == y) t++;
  return t;
}
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  scanf("%s%s", a, b);
  int sm = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      sm++;
    }
  }
  int ds = n - sm;
  int an, bn, cn, dn;
  bool flag = false;
  for (int i = 0; i < ds; i++) {
    dn = i;
    cn = ds - 2 * dn;
    if (cn < 0) break;
    bn = t - cn - i;
    if (bn < 0) continue;
    an = sm - bn;
    if (an < 0) continue;
    flag = true;
    break;
  }
  if (flag == false) {
    printf("-1\n");
    return 0;
  }
  int ad = dn, bd = dn;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (an > 0) {
        c[i] = a[i];
        an--;
      } else {
        c[i] = 'z' == a[i] ? 'a' : a[i] + 1;
      }
    } else {
      if (cn > 0) {
        c[i] = getc(a[i], b[i]);
        cn--;
      } else {
        if (ad > 0) {
          c[i] = a[i];
          ad--;
        } else {
          c[i] = b[i];
        }
      }
    }
  }
  c[n] = '\0';
  printf("%s\n", c);
}
