#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10, lg = 20;
int n, l[lg][maxn], r[lg][maxn], mn[lg][maxn], mx[lg][maxn], ans[maxn],
    sg[maxn][2];
void init() {
  for (int j = 1; j < lg; j++) {
    for (int i = 1; i + (1 << j) - 1 <= 3 * n; i++) {
      mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
      mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
    }
  }
}
int bp(int x) { return (31 - __builtin_clz(x)); }
int f(int c, int l, int r) {
  int p = bp(r - l + 1);
  if (c) {
    return max(mx[p][l], mx[p][r - (1 << p) + 1]);
  } else {
    return min(mn[p][l], mn[p][r - (1 << p) + 1]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    l[0][i] = max(1, i - a);
    l[0][n + i] = n + i - a;
    l[0][2 * n + i] = 2 * n + i - a;
    r[0][i] = i + a;
    r[0][n + i] = n + i + a;
    r[0][2 * n + i] = min(3 * n, 2 * n + i + a);
  }
  for (int j = 1; j < lg; j++) {
    for (int i = 1; i <= 3 * n; i++) {
      mn[0][i] = l[j - 1][i];
      mx[0][i] = r[j - 1][i];
    }
    init();
    for (int i = 1; i <= 3 * n; i++) {
      l[j][i] = f(0, l[j - 1][i], r[j - 1][i]);
      r[j][i] = f(1, l[j - 1][i], r[j - 1][i]);
    }
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    sg[i][0] = i, sg[i][1] = i;
  }
  for (int j = lg - 2; j >= 0; j--) {
    for (int i = 1; i <= 3 * n; i++) {
      mn[0][i] = l[j][i];
      mx[0][i] = r[j][i];
    }
    init();
    for (int i = n + 1; i <= 2 * n; i++) {
      if (f(1, sg[i][0], sg[i][1]) - f(0, sg[i][0], sg[i][1]) + 1 < n) {
        ans[i] += (1 << j);
        int a = f(0, sg[i][0], sg[i][1]);
        int b = f(1, sg[i][0], sg[i][1]);
        sg[i][0] = a;
        sg[i][1] = b;
      }
    }
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    cout << ans[i] + (n > 1) << " ";
  }
  return 0;
}
