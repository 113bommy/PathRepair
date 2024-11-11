#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long double eps = 1e-16;
const int maxn = 110000;
vector<int> a[1000010][2];
int last = 0;
vector<int> res;
bool rec(int r) {
  int x = ++last;
  if (a[x][0].size()) {
    if (a[x][0][0] <= last) {
      return false;
    }
    if (!rec(a[x][0].back())) {
      return false;
    }
  }
  res.push_back(x);
  if (a[x][1].size()) {
    if (a[x][1][0] <= last) {
      return false;
    }
    if (!rec(max(r, a[x][1].back()))) {
      return false;
    }
  } else if (last < r) {
    return rec(r);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    char s[10];
    scanf("%d%d%s", &x, &y, &s);
    a[x][s[0] != 'L'].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      sort(a[i][j].begin(), a[i][j].end());
    }
  }
  if (!rec(n)) {
    printf("IMPOSSIBLE");
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d ", res[i]);
    }
  }
  return 0;
}
