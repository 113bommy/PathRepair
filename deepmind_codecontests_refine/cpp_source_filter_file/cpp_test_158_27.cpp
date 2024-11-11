#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int x[15];
char s[15][10005];
int v[10005], cnt[25], tmp[25];
int P[10005];
int ans;
void dfs(int p, int sum) {
  if (p == n + 1) {
    int cur = m, res = sum;
    for (int i = 20; i >= 0; i--) {
      res += (i - 10) * (cur * 2 - cnt[i] + 1) * cnt[i] / 2;
      cur -= cnt[i];
    }
    tmp[0] = cnt[0];
    for (int i = 1; i <= 20; i++) tmp[i] = tmp[i - 1] + cnt[i];
    if (ans < res) {
      ans = res;
      for (int i = 1; i <= m; i++) {
        P[i] = tmp[v[i] + 10]--;
      }
    }
    return;
  }
  for (int i = 1; i <= m; i++) {
    if (s[p][i] == '1') {
      cnt[v[i] + 10]--;
      v[i]++;
      cnt[v[i] + 10]++;
    }
  }
  dfs(p + 1, sum - x[p]);
  for (int i = 1; i <= m; i++) {
    if (s[p][i] == '1') {
      cnt[v[i] + 10]--;
      v[i] -= 2;
      cnt[v[i] + 10]++;
    }
  }
  dfs(p + 1, sum + x[p]);
  for (int i = 1; i <= m; i++) {
    if (s[p][i] == '1') {
      cnt[v[i] + 10]--;
      v[i]++;
      cnt[v[i] + 10]++;
    }
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &s[i][1]);
  }
  for (int i = 1; i <= m; i++) v[i] = 0;
  for (int i = 0; i <= 20; i++) cnt[i] = 0;
  cnt[10] = m;
  ans = 0;
  dfs(1, 0);
  for (int i = 1; i <= m; i++) printf("%d ", P[i]);
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
