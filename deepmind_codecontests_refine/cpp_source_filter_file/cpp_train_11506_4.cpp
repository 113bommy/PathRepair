#include <bits/stdc++.h>
using namespace std;
char s[90];
void error() {
  cout << -1 << endl;
  exit(0);
}
int main() {
  int n, m, l = 1, r;
  scanf("%d%d\n", &n, &m);
  r = n;
  while (m--) {
    int v;
    scanf("To the %s of %d\n", s, &v);
    if (!strcmp(s, "left")) {
      if (l >= v) error();
      if (r > v) r = v - 1;
    } else {
      if (r <= v) error();
      if (l < v) l = v + 1;
    }
  }
  cout << r - l + 1 << endl;
  return 0;
}
