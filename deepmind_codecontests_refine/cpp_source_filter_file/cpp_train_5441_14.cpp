#include <bits/stdc++.h>
const int N = 1e6 + 5;
const int INF = 1e9;
int n, xi[N], yi[N], ansb, ansn;
char s[N];
using std::cin;
using std::cout;
bool jud(int md) {
  int xma = INF, xmi = 0, yma = INF, ymi = 0, dma = INF, dmi = -INF;
  for (int i = 1; i <= n; i++) {
    xmi = std::max(xmi, xi[i] - md);
    xma = std::min(xma, xi[i] + md);
    ymi = std::max(ymi, yi[i] - md);
    yma = std::min(yma, yi[i] + md);
    dma = std::min(dma, xi[i] - yi[i] + md);
    dmi = std::max(dmi, xi[i] - yi[i] - md);
  }
  if (xmi > xma || ymi > yma || dmi > dma) return false;
  ymi = std::max(ymi, xmi - dma);
  yma = std::min(yma, xma - dmi);
  if (ymi > yma) return false;
  for (int x = xmi; x <= xma; x++) {
    int rymin = std::max(ymi, x - dma), rymax = std::min(yma, x - dmi);
    if (rymin <= rymax && (x > 0 || rymax > 0)) {
      ansb = x, ansn = (x == 0) ? rymax : rymin;
      break;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int m = strlen(s);
    for (int v = 0; v < m; v++)
      if (s[v] == 'N')
        ++xi[i];
      else
        ++yi[i];
  }
  int l = 0, r = 2e6, md, ans = INF;
  while (l <= r) {
    md = l + r >> 1;
    if (jud(md)) {
      ans = md;
      r = md - 1;
    } else {
      l = md + 1;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ansb; i++) putchar('B');
  for (int i = 1; i <= ansn; i++) putchar('N');
  return 0;
}
