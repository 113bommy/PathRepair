#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
int p[110 * 110], ps;
char ans[110 << 1][110 << 1];
void locateb() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (a-- == 0) return;
      p[ps++] = 0;
    }
}
void locatew() {
  for (int i = 1; i <= b; ++i) p[ps++] = 15;
}
int ULfind(int u, int l) {
  int rt[4] = {6, 3, 12, 9};
  return rt[(l << 1) + u];
}
int URfind(int u, int r) {
  int rt[4] = {12, 9, 6, 3};
  return rt[(r << 1) + u];
}
void locatebw(int k, int t) {
  if (ps % m) {
    for (int i = ps; i < ps + m - ps % m; ++i)
      if (i < m)
        p[i] = ULfind(t, (p[i - 1] & 2) > 0);
      else
        p[i] = ULfind((p[i - m] & 4) > 0, (p[i - 1] & 2) > 0);
    p[ps + m - 1] = p[ps];
    for (int i = ps + m - 2; i >= ps + m - ps % m; --i)
      p[i] = URfind((p[i - m] & 4) > 0, (p[i + 1] & 8) > 0);
    ps += m, k -= m;
  }
  if (ps >= n * m) return;
  for (int i = 0; i < k; ++i) {
    if (ps < m) {
      if (ps == 0)
        p[ps++] = 6;
      else
        p[ps++] = ULfind(t, (p[ps - 1] & 2) > 0);
    } else {
      if (ps % m == 0)
        p[ps++] = (p[ps - m] & 4) ? 3 : 12;
      else
        p[ps++] = ULfind((p[ps - m] & 4) > 0, (p[ps - 1] & 2) > 0);
    }
  }
}
void getans(int i, int j, int t) {
  char c0, c1, c2, c3;
  if (t == 0)
    c0 = '#', c1 = '#', c2 = '#', c3 = '#';
  else if (t == 15)
    c0 = '.', c1 = '.', c2 = '.', c3 = '.';
  else if (t == 12)
    c0 = '\\', c1 = '#', c2 = '.', c3 = '\\';
  else if (t == 9)
    c0 = '.', c1 = '/', c2 = '/', c3 = '#';
  else if (t == 3)
    c0 = '\\', c1 = '.', c2 = '#', c3 = '\\';
  else
    c0 = '#', c1 = '/', c2 = '/', c3 = '.';
  ans[2 * i][2 * j] = c0, ans[2 * i][2 * j + 1] = c1,
                 ans[2 * i + 1][2 * j] = c2, ans[2 * i + 1][2 * j + 1] = c3;
}
void disp() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) getans(i, j, p[i * m + j]);
  n <<= 1, m <<= 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%c", ans[i][j]);
    puts("");
  }
}
int main() {
  while (~scanf("%d%d%d%d%d", &n, &m, &a, &b, &c)) {
    ps = 0;
    locateb();
    locatebw(m, 0);
    locatew();
    locatebw(c - m, 1);
    disp();
  }
  return 0;
}
