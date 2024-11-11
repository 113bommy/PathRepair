#include <bits/stdc++.h>
using namespace std;
int a[40];
int data1[300005];
int data2[300005];
int cnt1;
int cnt2;
int n, m;
void dfs1(int sum, int i, int n) {
  if (i > (n - 1) / 2) {
    data1[cnt1++] = sum;
    return;
  }
  dfs1((sum + a[i]) % m, i + 1, n);
  dfs1(sum % m, i + 1, n);
}
void dfs2(int sum, int i, int n) {
  if (i >= n) {
    data2[cnt2++] = sum;
    return;
  }
  dfs2((sum + a[i]) % m, i + 1, n);
  dfs2(sum % m, i + 1, n);
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cnt1 = 0;
    cnt2 = 0;
    dfs1(0, 0, n);
    dfs2(0, (n - 1) / 2 + 1, n);
    sort(data2, data2 + cnt2);
    int ans = 0;
    for (int i = 0; i < cnt1; i++) {
      int x = m - data1[i];
      int p1 = lower_bound(data2, data2 + cnt2, x) - data2;
      if (p1 > 0) {
        ans = max(ans, (data1[i] + data2[p1 - 1]) % m);
      }
      ans = max(ans, (data1[i] + data2[cnt2 - 1]) % m);
    }
    printf("%d\n", ans);
  }
}
