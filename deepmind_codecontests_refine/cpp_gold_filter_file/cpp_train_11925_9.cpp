#include <bits/stdc++.h>
using namespace std;
int ans;
int cnt1, cnt2;
int vis[10];
int n, m;
int getNum(int x) {
  int cnt = 1;
  while (x >= 7) {
    x /= 7;
    cnt++;
  }
  return cnt;
}
void dfs(int d, int sum) {
  if (d > cnt1 + cnt2) return;
  if (d <= cnt1 && sum >= n) return;
  if (d > cnt1 && sum >= m) return;
  if (d == cnt1 + cnt2) {
    ans++;
    return;
  }
  for (int i = 0; i < 7; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      if (d == cnt1)
        dfs(d + 1, i);
      else
        dfs(d + 1, sum * 7 + i);
      vis[i] = 0;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  cnt1 = getNum(n - 1), cnt2 = getNum(m - 1);
  if (n == 1) cnt1 = 1;
  if (m == 1) cnt2 = 1;
  if (cnt1 + cnt2 > 7)
    printf("0\n");
  else {
    dfs(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
