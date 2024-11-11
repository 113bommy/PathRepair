#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int in[maxn], out[maxn];
int p[maxn], q[maxn];
int f[maxn], g[maxn];
int n;
int main() {
  int maxx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &out[i], &in[i]), p[i] = q[i] = i, maxx = max(maxx, in[i]);
  sort(p + 1, p + 1 + n, [](int i, int j) { return in[i] < in[j]; });
  sort(q + 1, q + 1 + n, [](int i, int j) { return out[i] < out[j]; });
  int j = 0;
  int mn = 0, cnt = 1;
  for (int i = 1; i <= n; i++) {
    while (j < n && out[q[j + 1]] <= in[p[i]]) {
      int id = q[++j];
      if (mn > f[id] - out[id]) {
        mn = f[id] - out[id];
        cnt = g[id];
      } else if (mn == f[id] - out[id]) {
        cnt = (cnt + g[id]) % mod;
      }
    }
    f[p[i]] = mn + in[p[i]];
    g[p[i]] = cnt;
  }
  int minn = 0x3f3f3f3f, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (out[i] <= maxx) continue;
    if (f[i] < minn) {
      minn = f[i];
      ans = g[i];
    } else if (f[i] == minn) {
      ans = (ans + g[i]) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
