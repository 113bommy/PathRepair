#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, q, k, o, s[N], v[N], lg[N], a[N], g[N], h[N][22];
long long f[N], ans[N];
vector<pair<int, int>> qr[N];
int find(int l, int r) {
  int k = lg[r - l + 1];
  return min(h[l][k], h[r - (1 << k) + 1][k]);
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), h[i][0] = a[i];
  for (int i = (2); i <= (n); i++) lg[i] = lg[i >> 1] + 1;
  for (int i = (1); i <= (20); i++)
    for (int j = (1); j <= (n); j++)
      if (j + (1 << i) - 1 <= n)
        h[j][i] = min(h[j][i - 1], h[j + (1 << i - 1)][i - 1]);
  for (int i = (1); i <= (q); i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    qr[l].push_back({r, i});
  }
  for (int i = (0); i <= (k - 1); i++) {
    o = 0, s[0] = n - i + k;
    for (int j = n - i; j >= 1; j -= k) {
      while (o && v[o] >= a[j]) o--;
      s[++o] = j, v[o] = a[j],
      f[o] = f[o - 1] + 1ll * (s[o - 1] - s[o]) / k * a[j];
      for (auto [x, se] : qr[j]) {
        int t = (x / k) * k + (n - i) % k, l = 1, r = o, as = 0;
        if (t > x) t -= k;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (s[mid] <= x)
            as = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        ans[se] = f[o] - f[as] + 1ll * ((t - s[as]) / k + 1) * v[as];
      }
      if (j < k) break;
      while (o && v[o] >= find(j - k + 1, j)) o--;
      s[++o] = j, v[o] = find(j - k + 1, j),
      f[o] = f[o - 1] + 1ll * (s[o - 1] - s[o]) / k * v[o];
    }
  }
  for (int i = (1); i <= (q); i++) printf("%d\n", ans[i]);
  return 0;
}
