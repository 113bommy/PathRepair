#include <bits/stdc++.h>
using namespace std;
vector<int> v[2];
int n, a[100005];
int b[2][100005];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  v[1].clear();
  v[0].clear();
  memset(b, 0, sizeof(b));
  v[n & 1].push_back(a[n]);
  b[n & 1][a[n]] = 1;
  int g = 0, ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    int now = i & 1, pre = now ^ 1;
    for (int j = 0; j < v[now].size(); j++) b[now][v[now][j]] = 0;
    v[now].clear();
    for (int j = 0; j < v[pre].size(); j++) {
      int p = v[pre][j];
      int id = max(((a[i] - 1) / p + 1), 1), num = a[i] / id;
      if (b[now][num] == 0) v[now].push_back(num);
      b[now][num] += b[pre][p];
      g = (g + 1ll * (id - 1) * b[pre][p]) % 998244353;
    }
    if (b[now][a[i]] == 0) v[now].push_back(a[i]);
    b[now][a[i]]++;
    ans = (ans + g) % 998244353;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
