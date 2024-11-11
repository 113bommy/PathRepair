#include <bits/stdc++.h>
using namespace std;
string s, w;
int n, q, tp, l, r, cnt;
int fn[56][4][100001];
int lnk[10][10];
void md(int y, char c, int x, int add) {
  int tp = 0;
  if (c == 'C') tp = 1;
  if (c == 'G') tp = 2;
  if (c == 'T') tp = 3;
  while (x <= n) {
    fn[y][tp][x] += add;
    x = (x | (x - 1)) + 1;
  }
}
int fsum(int y, int x, char c) {
  int tp = 0;
  if (c == 'C') tp = 1;
  if (c == 'G') tp = 2;
  if (c == 'T') tp = 3;
  int s = 0;
  while (x >= 1) {
    s += fn[y][tp][x];
    x = (x & (x - 1));
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  n = s.size();
  s = '#' + s;
  for (int j = 1; j <= 10; j++)
    for (int k = 0; k < j; k++) {
      cnt++;
      lnk[j][k] = cnt;
    }
  for (int j = 1; j <= 10; j++) {
    for (int i = 1; i <= n; i++) md(lnk[j][i % j], s[i], i, 1);
  }
  cin >> q;
  for (; q >= 1; q--) {
    int tp, l, r;
    char c;
    cin >> tp >> l;
    if (tp == 1) {
      cin >> c;
      char last = s[l];
      s[l] = c;
      for (int j = 1; j <= 10; j++) {
        md(lnk[j][l % j], last, l, -1);
        md(lnk[j][l % j], s[l], l, 1);
      }
    } else {
      cin >> r >> w;
      int ans = 0;
      for (int j = 0; j < min((int)w.size(), r - l); j++)
        ans += fsum(lnk[w.size()][(l + j) % w.size()], r, w[j]) -
               fsum(lnk[w.size()][(l + j) % w.size()], l - 1, w[j]);
      cout << ans << "\n";
    }
  }
  return 0;
}
