#include <bits/stdc++.h>
using namespace std;
int sg[2][2][300005], v[4];
long long a[300005];
int repeat;
int cal(long long x, int j, int k) {
  if (x < repeat) {
    return sg[j][k][x];
  } else {
    return sg[j][k][(x - 1000) % repeat + 1000];
  }
}
void work() {
  int n, x, y, z;
  scanf("%d%d%d%d", &n, &x, &y, &z);
  int maxx = 1000;
  for (int i = 1; i <= maxx * 3; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        for (int l = 0; l <= 3; l++) {
          v[l] = 0;
        }
        v[sg[1][1][max(0, i - x)]] = 1;
        if (j) v[sg[0][1][max(0, i - y)]] = 1;
        if (k) v[sg[1][0][max(0, i - z)]] = 1;
        for (int l = 0; l <= 3; l++) {
          if (v[l] == 0) {
            sg[j][k][i] = l;
            break;
          }
        }
      }
    }
  }
  for (repeat = 1; repeat <= maxx; repeat++) {
    bool f = 1;
    for (int i = 0; i <= maxx - 1; i++) {
      for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 1; k++) {
          if (sg[j][k][i + maxx] != sg[j][k][i + maxx + repeat]) {
            f = 0;
            break;
          }
        }
        if (!f) break;
      }
      if (!f) break;
    }
    if (f) {
      break;
    }
  }
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum ^= cal(a[i], 1, 1);
  }
  for (int i = 1; i <= n; i++) {
    int tmp = sum ^ cal(a[i], 1, 1);
    if (tmp == cal(max(0ll, a[i] - x), 1, 1)) ans++;
    if (tmp == cal(max(0ll, a[i] - y), 0, 1)) ans++;
    if (tmp == cal(max(0ll, a[i] - z), 1, 0)) ans++;
  }
  printf("%d\n", ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
}
