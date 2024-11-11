#include <bits/stdc++.h>
using namespace std;
int n;
int tot, cnt;
int a[5010], c[5010];
int b[5010][5010], b2[5010][5010];
int sum(int x) {
  int res(0);
  while (x) res += c[x], x -= (x & (-x));
  return res;
}
void add(int x, int d) {
  while (x <= n) c[x] += d, x += (x & (-x));
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    a[i] = ++x;
  }
  for (int i = n; i >= 1; i--) tot += sum(a[i]), add(a[i], 1);
  for (int i = n; i >= 1; i--) {
    memset(c, 0, sizeof(c));
    for (int j = n; j >= i; j--) {
      if (a[j] > a[i]) add(a[j], 1);
      b[i][j] = sum(n) - sum(a[i] - 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(c, 0, sizeof(c));
    for (int j = 1; j <= i; j++) {
      if (a[j] > a[i]) add(a[j], 1);
      b2[i][j] = sum(n) - sum(a[i] - 1);
    }
  }
  int minn = tot;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] >= a[j]) {
        int t1 = 2 * (b[i][i + 1] - b[i][j]) - (j - (i + 1));
        int t2 = j - (i + 1) - (b2[j][j - 1] - b2[j][i]) * 2;
        int ans = tot + t1 + t2 - 1;
        if (ans < minn)
          minn = ans, cnt = 1;
        else if (ans == minn)
          cnt++;
      }
  printf("%d %d", minn, cnt);
  return 0;
}
