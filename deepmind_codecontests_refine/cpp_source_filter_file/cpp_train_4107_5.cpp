#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int a[100010], stk[100010];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    v[a[i]].push_back(i);
  }
  long long now = 0;
  for (int i = 2; i <= m; i++) now += (long long)abs(a[i - 1] - a[i]);
  long long ans = now;
  for (int i = 1; i <= n; i++)
    if (v[i].size()) {
      int cnt = 0;
      long long pre = 0;
      for (int j = 0; j < v[i].size(); j++) {
        int p = v[i][j];
        if (p == 1) {
          pre += (long long)abs(a[1] - a[2]);
          if (a[2] != i) stk[++cnt] = a[2];
        } else if (p == m) {
          pre += (long long)abs(a[m - 1] - a[m]);
          if (a[m - 1] != i) stk[++cnt] = a[m - 1];
        } else {
          pre += (long long)abs(a[p - 1] - a[p]) + abs(a[p] - a[p + 1]);
          if (a[p - 1] != i) stk[++cnt] = a[p - 1];
          if (a[p + 1] != i) stk[++cnt] = a[p + 1];
        }
      }
      sort(stk + 1, stk + cnt + 1);
      int change = stk[cnt / 2];
      long long last = 0;
      for (int j = 1; j + j <= cnt; j++)
        last += (long long)(stk[cnt + 1 - j] - stk[j]);
      if (now - pre + last < ans) ans = now - pre + last;
    }
  printf("%I64d\n", ans);
  return 0;
}
