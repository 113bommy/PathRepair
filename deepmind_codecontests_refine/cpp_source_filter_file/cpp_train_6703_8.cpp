#include <bits/stdc++.h>
using namespace std;
struct sq {
  int w;
  char c;
};
int a[1000][1000], a1[1000][1000];
sq d[1000][1000], d1[1000][1000];
int main() {
  int n, w, x;
  x = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &w);
      if (!w) {
        x = i;
        w = 10;
      }
      while (!(w % 2)) {
        a[i][j]++;
        w /= 2;
      }
      while (!(w % 5)) {
        a1[i][j]++;
        w /= 5;
      }
    }
  d[0][0].w = a[0][0];
  d1[0][0].w = a1[0][0];
  for (int i = 1; i < n; i++) {
    d[i][0].w = d[i - 1][0].w + a[i][0];
    d[i][0].c = 'D';
    d[0][i].w = d[0][i - 1].w + a[0][i];
    d[0][i].c = 'R';
    d1[i][0].w = d1[i - 1][0].w + a1[i][0];
    d1[i][0].c = 'D';
    d1[0][i].w = d1[0][i - 1].w + a1[0][i];
    d1[0][i].c = 'R';
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      if (d[i - 1][j].w < d[i][j - 1].w) {
        d[i][j].w = d[i - 1][j].w + a[i][j];
        d[i][j].c = 'D';
      } else {
        d[i][j].w = d[i][j - 1].w + a[i][j];
        d[i][j].c = 'R';
      }
      if (d1[i - 1][j].w < d1[i][j - 1].w) {
        d1[i][j].w = d1[i - 1][j].w + a1[i][j];
        d1[i][j].c = 'D';
      } else {
        d1[i][j].w = d1[i][j - 1].w + a1[i][j];
        d1[i][j].c = 'R';
      }
    }
  int x1, x2, y1, y2, k, m;
  k = d[n - 1][n - 1].w;
  m = d1[n - 1][n - 1].w;
  x1 = x2 = y1 = y2 = n - 1;
  string s, s1;
  while (d[x1][y1].c) {
    s += d[x1][y1].c;
    if (d[x1][y1].c == 'D')
      x1--;
    else
      y1--;
    s1 += d1[x2][y2].c;
    if (d1[x2][y2].c == 'D')
      x2--;
    else
      y2--;
  }
  for (int i = 0; i < s.size() / 2; i++) {
    swap(s[i], s[s.size() - 1 - i]);
    swap(s1[i], s1[s1.size() - 1 - i]);
  }
  if (x != -1 && min(k, m)) {
    cout << '1' << endl;
    for (int i = 0; i < x; i++) cout << 'D';
    for (int i = 0; i < n - 1; i++) cout << 'R';
    for (int i = 0; i < n - x; i++) cout << 'D';
    cout << endl;
  } else if (k < m)
    cout << k << endl << s << endl;
  else
    cout << m << endl << s1 << endl;
  return 0;
}
