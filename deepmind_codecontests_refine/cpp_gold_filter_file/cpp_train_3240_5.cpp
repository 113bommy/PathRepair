#include <bits/stdc++.h>
using namespace std;
const int N = 205, P = 998244353, inv2 = (P + 1) / 2, inv6 = (P + 1) / 6;
int n, T, ans;
int sx[N], sy[N], c[N][N];
vector<int> kt;
int s1(int x) { return 1ll * x * (x + 1) / 2 % P; }
int s2(int x) { return 1ll * x * (x + 1) % P * (2 * x + 1) % P * inv6 % P; }
int calc(int t) {
  int hc = 0, res = 0;
  int h[N];
  memset(h, 0, sizeof(h));
  for (int i = 1; i <= n; i++) {
    h[++hc] = sx[i] - t - 1;
    h[++hc] = sy[i] - t - 1;
    h[++hc] = sx[i] + t;
    h[++hc] = sy[i] + t;
  }
  sort(h + 1, h + hc + 1);
  hc = unique(h + 1, h + hc + 1) - (h + 1);
  for (int i = 1; i <= n; i++) {
    int r1 = lower_bound(h + 1, h + hc + 1, sx[i] - t - 1) - h,
        c1 = lower_bound(h + 1, h + hc + 1, sy[i] - t - 1) - h;
    int r2 = lower_bound(h + 1, h + hc + 1, sx[i] + t) - h,
        c2 = lower_bound(h + 1, h + hc + 1, sy[i] + t) - h;
    c[r1 + 1][c1 + 1]++;
    c[r1 + 1][c2 + 1]--;
    c[r2 + 1][c1 + 1]--;
    c[r2 + 1][c2 + 1]++;
  }
  for (int i = 1; i <= hc; i++)
    for (int j = 1; j <= hc; j++) c[i][j] += c[i][j - 1];
  for (int i = 1; i <= hc; i++)
    for (int j = 1; j <= hc; j++) {
      c[i][j] += c[i - 1][j];
      if (c[i][j])
        res = (res + 1ll * (h[i] - h[i - 1]) * (h[j] - h[j - 1])) % P;
    }
  memset(c, 0, sizeof(c));
  return res;
}
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d%d", sx + i, sy + i);
  ans = 1ll * T * calc(T) % P;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      kt.push_back((max(abs(sx[i] - sx[j]), abs(sy[i] - sy[j])) - 1) / 2);
  kt.push_back(-1);
  kt.push_back(T - 1);
  sort(kt.begin(), kt.end());
  int cnts = unique(kt.begin(), kt.end()) - kt.begin();
  for (int i = 1; i < cnts; i++) {
    int l = kt[i - 1] + 1, r = kt[i];
    if (r >= T) break;
    if (r - l + 1 < 3) {
      for (int j = l; j <= r; j++) ans = (ans - calc(j)) % P;
      continue;
    }
    int v1 = calc(l), v2 = calc(l + 1), v3 = calc(l + 2);
    int A = (1ll * v3 - 2ll * v2 + v1) % P,
        B = (v2 - v1 - 1ll * (l + 1) * A) % P;
    A = 1ll * A * inv2 % P;
    B = (B + A) % P;
    int C = (v1 - 1ll * A * l % P * l - 1ll * B * l) % P;
    ans = (ans - 1ll * A * (s2(r) - s2(l - 1)) - 1ll * B * (s1(r) - s1(l - 1)) -
           1ll * C * (r - l + 1)) %
          P;
  }
  printf("%d\n", (ans + P) % P);
  return 0;
}
