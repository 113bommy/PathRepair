#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int a[maxn], b[110], last[maxn];
int sum[maxn];
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt = max(++b[a[i]], cnt);
  vector<int> d;
  for (int i = 1; i <= min(100, n); i++)
    if (b[i] == cnt) d.push_back(i);
  if (d.size() > 1)
    printf("%d\n", n);
  else {
    int ans = 0;
    int m = d[0];
    for (int i = 1; i <= min(100, n); i++) {
      if (!b[i] || i == m) continue;
      sum[0] = 0;
      memset(last, -1, sizeof(last));
      last[0] = 0;
      for (int j = 1; j <= n; j++) {
        sum[j] = sum[j - 1];
        if (a[j] == m)
          sum[j]++;
        else if (a[j] == i)
          sum[j]--;
        if (last[sum[j]] == -1) last[sum[j]] = j;
      }
      for (int j = n; j >= 1; j--) {
        ans = max(ans, j - last[sum[j]]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
