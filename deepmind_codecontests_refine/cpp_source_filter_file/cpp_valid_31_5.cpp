#include <bits/stdc++.h>
using namespace std;
const int K = 19, N = 1 << K, INF = 0x3f3f3f3f;
int n, k, cnt[N], a[N], ans[K][K];
vector<int> b[N], c[N];
void ckmin(int &x, int y) {
  if (y < x) x = y;
}
void calc(vector<int> v, int s, int t) {
  if (v.size() < 2) return;
  if (s < t) {
    for (int i = 0; i < 1 << t; i++)
      ckmin(ans[s][i], abs((v[0] ^ i) - (v[1] ^ i)));
    return;
  }
  for (int i = 0; i < 1 << (s + 1); i++) c[i].clear();
  for (int i = 0; i < 1 << t; i++)
    for (auto u : v) {
      int to = i ^ (1 << s);
      c[to ^ u].push_back(to), to = i ^ (((1 << (s - t)) - 1) << t),
                               c[to ^ u].push_back(to);
    }
  for (int i = 0; i < 1 << (s + 1); i++) {
    int mn = INF;
    sort(c[i].begin(), c[i].end());
    for (int j = 1; j < c[i].size(); j++) ckmin(mn, c[i][j] - c[i][j - 1]);
    ckmin(ans[s][i], mn);
  }
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int p = 0;
  for (int i = 1; i <= k; i++) {
    int mx = 0;
    for (int j = 0; j < 1 << k; j++) cnt[j] = 0;
    for (int j = 0; j < n; j++) cnt[a[j] >> i]++;
    for (int j = 0; j < 1 << k; j++) mx = max(mx, cnt[j]);
    if (mx > 1) {
      p = i;
      break;
    }
  }
  memset(ans, 0x3f, sizeof(ans));
  for (int i = p - 1; i < k; i++) {
    for (int j = 0; j < 1 << (k - i - 1); j++) b[j].clear();
    for (int j = 0; j < n; j++)
      b[a[j] >> (i + 1)].push_back(a[j] & ((1 << (i + 1)) - 1));
    for (int j = 0; j < 1 << (k - i - 1); j++) calc(b[j], i, p);
  }
  for (int i = 0; i < 1 << k; i++) {
    int mn = INF;
    for (int j = p - 1; j < k; j++) ckmin(mn, ans[j][i & ((1 << (j + 1)) - 1)]);
    printf("%d ", mn);
  }
}
