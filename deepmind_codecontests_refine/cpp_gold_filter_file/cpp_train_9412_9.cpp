#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int num[22];
bool f[1 << 21];
int be[100010];
void dfs(int sta) {
  if (f[sta]) return;
  f[sta] = true;
  for (int i = 0; i < m; i++)
    if ((sta & (1 << i))) dfs(sta - (1 << i));
}
int cnt(int sta) {
  int ret = 0;
  for (int i = 0; i < m; i++)
    if (sta & (1 << i)) ret++;
  return ret;
}
int main() {
  memset(f, 0, sizeof(f));
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int tot;
    scanf("%d", &tot);
    for (int j = 0; j < tot; j++) {
      int x;
      scanf("%d", &x);
      be[x] = i;
    }
  }
  memset(num, 0, sizeof(num));
  int sta = 0;
  for (int i = 1; i <= d; i++) {
    num[be[i]]++;
    if (num[be[i]] > 0) {
      sta |= (1 << be[i]);
    }
  }
  int ma = (1 << m);
  dfs(ma - 1 - sta);
  for (int i = d + 1; i <= n; i++) {
    num[be[i]]++;
    if (num[be[i]] > 0) {
      sta |= (1 << be[i]);
    }
    num[be[i - d]]--;
    if (num[be[i - d]] == 0) {
      sta -= (1 << be[i - d]);
    }
    dfs(ma - 1 - sta);
  }
  int ans = m;
  for (int i = 0; i < ma; i++)
    if (!f[i]) ans = min(ans, cnt(i));
  cout << ans << endl;
}
