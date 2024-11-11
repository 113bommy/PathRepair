#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
int n, m, q;
int x[200003], y[200003], ans[200003];
int dp[1003][1003];
struct data {
  int l, r, s, t, id;
} a[200003];
inline void insert(int id) {
  for (int i = 1; i <= n; i++) {
    if (i == x[id]) {
      dp[i][y[id]] = id;
    } else if (i == y[id]) {
      dp[i][x[id]] = id;
    } else if (dp[x[id]][i] < dp[y[id]][i]) {
      dp[y[id]][i] = dp[x[id]][i];
    } else {
      dp[x[id]][i] = dp[y[id]][i];
    }
  }
}
inline bool cmp(data a, data b) { return a.l > b.l; }
int main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        dp[i][j] = m + 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    x[i] = read(), y[i] = read();
  }
  for (int i = 1; i <= q; i++) {
    a[i].l = read(), a[i].r = read(), a[i].s = read(), a[i].t = read();
    a[i].id = i;
  }
  sort(a + 1, a + q + 1, cmp);
  int j = m;
  for (int i = 1; i <= q; i++) {
    while (j >= a[i].l && j) {
      insert(j);
      j--;
    }
    ans[a[i].id] = dp[a[i].s][a[i].t] <= a[i].r;
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i]) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
