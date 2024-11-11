#include <bits/stdc++.h>
using namespace std;
bool vis[110];
int prime[110], cnt;
void init(int mx) {
  for (int i = 2; i <= mx; i++) {
    if (!vis[i]) {
      prime[++cnt] = i;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= mx; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
int a[3000010], f[3000010];
bool b[3000010];
int l, r, p;
void dfs(int x, int k) {
  a[++a[0]] = k;
  for (int i = x; i <= cnt; i++) {
    if ((long long)prime[i] * k <= r) {
      dfs(i, k * prime[i]);
    }
  }
}
int main() {
  cin >> l >> r >> p;
  init(p);
  dfs(1, 1);
  sort(a + 1, a + a[0] + 1);
  for (int i = 1; i <= a[0]; i++) {
    f[i] = 0x3f3f3f3f;
  }
  f[1] = 0, b[1] = 1;
  int ans = 0;
  for (int i = 2; i <= p; i++) {
    int j = i;
    for (int k = 1; k <= a[0]; k++) {
      while ((j <= a[0]) && (a[j] != a[k] * i)) {
        j++;
      }
      if (j > a[0]) {
        break;
      }
      if (f[k] + 1 < f[j]) {
        f[j] = f[k] + 1;
      }
      if ((a[j] < l) || b[j]) {
        continue;
      }
      if (f[j] + i <= p) {
        b[j] = 1;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
