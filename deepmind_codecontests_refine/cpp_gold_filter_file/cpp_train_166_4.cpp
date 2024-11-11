#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int sz = 0;
int n, m;
struct item {
  int l, r, u, d;
  char c;
  item() {
    l = r = u = d = -1;
    c = '.';
  }
};
item a[5010], b[5010];
int up[5010];
int calc(int num) {
  int help = num, kol = 0;
  while (help != -1) {
    a[a[help].l].r = a[help].r;
    a[a[help].r].l = a[help].l;
    a[a[help].u].d = a[help].d;
    a[a[help].d].u = a[help].u;
    if (a[help].c == 'L')
      help = a[help].l;
    else if (a[help].c == 'R')
      help = a[help].r;
    else if (a[help].c == 'U')
      help = a[help].u;
    else
      help = a[help].d;
    kol++;
  }
  return kol;
}
int main() {
  scanf("%d %d\n", &n, &m);
  memset(up, -1, sizeof(up));
  for (int i = 0; i < int(n); i++) {
    int tek = -1;
    for (int j = 0; j < int(m); j++) {
      char c;
      scanf("%c", &c);
      if (c == '.') continue;
      a[sz].l = tek;
      a[sz].u = up[j];
      a[sz].c = c;
      if (up[j] != -1) a[up[j]].d = sz;
      if (tek != -1) a[tek].r = sz;
      tek = sz;
      up[j] = sz++;
    }
    scanf("\n");
  }
  for (int i = 0; i < int(sz); i++) b[i] = a[i];
  int maxx = 0, maxkol = 0;
  for (int i = 0; i < int(sz); i++) {
    int k = calc(i);
    if (k > maxx) {
      maxx = k;
      maxkol = 1;
    } else if (k == maxx)
      maxkol++;
    for (int j = 0; j < int(sz); j++) a[j] = b[j];
  }
  cout << maxx << ' ' << maxkol << endl;
  return 0;
}
