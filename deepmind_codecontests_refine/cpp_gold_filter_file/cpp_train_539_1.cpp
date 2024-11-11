#include <bits/stdc++.h>
using namespace std;
int n, l, t;
char s[1005 * 1005];
int len;
string st[1005];
int main() {
  scanf("%d%d%d", &n, &l, &t);
  scanf("%s", &s);
  len = n * l;
  sort(s, s + len);
  int piv = 0;
  int pos = 0;
  while (pos < len && piv < (t - 1)) {
    if (st[t - 1].size() == l) {
      break;
    }
    for (int i = piv; i < t; i++) {
      st[i] += s[pos++];
    }
    while (piv < (t - 1) && st[piv] < st[t - 1]) piv++;
  }
  while (st[t - 1].size() < l) st[t - 1] += s[pos++];
  for (int i = 0; i < n; i++) {
    while (st[i].size() < l) st[i] += s[pos++];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) printf("%c", st[i][j]);
    printf("\n");
  }
  return 0;
}
