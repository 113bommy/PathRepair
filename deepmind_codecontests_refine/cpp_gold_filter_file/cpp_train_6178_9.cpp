#include <bits/stdc++.h>
using namespace std;
const int N = 212;
int a[N], b[N], s, ans1[N * 2], ans2[N * 2], ans = 0, t, x, n, m, num[N];
int sum[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &num[i]);
    for (int j = 1; j <= num[i]; ++j) scanf("%d", &x), a[x] = sum[i - 1] + j;
    sum[i] = sum[i - 1] + num[i];
  }
  for (int i = 1; i <= sum[m]; ++i) {
    if (a[i] != 0) {
      for (int j = i + 1; j <= n; ++j)
        if (a[j] == 0) {
          ++ans;
          ans1[ans] = i;
          ans2[ans] = j;
          swap(a[i], a[j]);
          break;
        }
    }
    for (int j = i; j <= n; ++j)
      if (a[j] == i) {
        ++ans;
        ans1[ans] = j;
        ans2[ans] = i;
        swap(a[i], a[j]);
        break;
      }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("%d %d\n", ans1[i], ans2[i]);
}
