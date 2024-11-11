#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
const double INF = 100000000000.0;
const long long MOD = 1000000009;
const int MAXN = 102400;
int n, m;
int x, y;
int l, r;
int view;
int ans;
char a[100][10010];
int same_level = 0;
int main() {
  scanf("%d%d\n", &n, &m);
  for (long long i = 0; i < n; ++i) scanf("%s", a[i]);
  view = 1;
  l = r = 0;
  while (x + 1 < n) {
    ++ans;
    ++same_level;
    if (a[x + 1][y] == '.') {
      same_level = 0;
      ++x;
      l = r = y;
      continue;
    }
    if (same_level > 300000) {
      printf("Never\n");
      return 0;
    }
    if (view == 1 && y + 1 < m && a[x][y + 1] == '.') {
      ++y;
      r = y;
      continue;
    }
    if (view == 2 && y > 0 && a[x][y - 1] == '.') {
      --y;
      l = y;
      continue;
    }
    if (view == 1) {
      ans += r - l;
      if (y + 1 < m && a[x][y + 1] == '+') r = y + 1;
      y = l;
      view = 2;
      continue;
    }
    if (view == 2) {
      view = 1;
      ans += r - l;
      if (y > 0 && a[x][y - 1] == '+') l = y - 1;
      y = r;
    }
  }
  cout << ans << endl;
}
