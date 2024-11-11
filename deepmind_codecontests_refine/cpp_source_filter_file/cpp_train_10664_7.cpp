#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, m;
char res[105][105];
int a[26];
char Find(int x, int y, int s) {
  for (int(i) = 0; (i) < (26); ++(i)) a[i] = 0;
  for (int i = y; i < y + s; ++i) {
    char c = res[x - 1][y];
    if (c >= 'A' && c <= 'Z') ++a[c - 'A'];
  }
  for (int i = y; i < y + s; ++i) {
    char c = res[x + s][y];
    if (c >= 'A' && c <= 'Z') ++a[c - 'A'];
  }
  for (int i = x; i < x + s; ++i) {
    char c = res[i][y - 1];
    if (c >= 'A' && c <= 'Z') ++a[c - 'A'];
  }
  for (int i = x; i < x + s; ++i) {
    char c = res[i][y + s];
    if (c >= 'A' && c <= 'Z') ++a[c - 'A'];
  }
  for (int(i) = 0; (i) < (26); ++(i))
    if (!a[i]) {
      return char('A' + i);
    }
}
void paint(int x, int y) {
  int pr = 0;
  int s = 1;
  char t = Find(x, y, 1);
  for (;; ++s) {
    if (x + s - 1 > n) {
      --s;
      break;
    }
    if (y + s - 1 > m) {
      --s;
      break;
    }
    if (Find(x, y, s) != t) {
      --s;
      break;
    }
    if (y + s <= m) {
      if (Find(x, y + s, 1) < t) {
        break;
      }
    }
    bool ok = true;
    for (int i = x; i <= x + s - 1; ++i) {
      if (res[i][y + s - 1] >= 'A' && res[i][y + s - 1] <= 'Z') {
        ok = false;
        break;
      }
    }
    for (int i = y; i <= y + s - 1; ++i) {
      if (!ok) break;
      if (res[x + s - 1][i] >= 'A' && res[x + s - 1][i] <= 'Z') {
        ok = false;
        break;
      }
    }
    if (!ok) {
      --s;
      break;
    }
  }
  char c = Find(x, y, s);
  for (int i = x; i < x + s; ++i)
    for (int j = y; j < y + s; ++j) res[i][j] = c;
}
int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!res[i][j]) paint(i, j);
      printf("%c", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}
