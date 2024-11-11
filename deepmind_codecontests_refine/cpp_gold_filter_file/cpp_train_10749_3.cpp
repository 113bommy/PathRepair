#include <bits/stdc++.h>
const int MAXN = 1e5;
int n, fa[20], trs[20], adj[20];
bool f[1 << 20];
char A[MAXN + 5], B[MAXN + 5];
inline int find(const int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }
inline int calc(const std::vector<int>& pts) {
  int mx = 0, sz = pts.size();
  for (int i = 0; i < sz; ++i) {
    adj[i] = 0;
    for (int j = 0; j < sz; ++j) {
      adj[i] |= ((trs[pts[i]] >> pts[j]) & 1) << j;
    }
  }
  for (int i = 0; i < 1 << sz; ++i) f[i] = false;
  f[0] = true;
  for (int s = 0; s < 1 << sz; ++s) {
    if (!f[s]) continue;
    if (int t = __builtin_popcount(s); mx < t) mx = t;
    for (int i = 0; i < sz; ++i) {
      if (!((s >> i) & 1) && !(adj[i] & s)) {
        f[s | (1 << i)] = true;
      }
    }
  }
  return sz * 2 - 1 - mx;
}
int main() {
  int T;
  std::vector<int> eff;
  for (scanf("%d", &T); T--;) {
    scanf("%d %s %s", &n, A + 1, B + 1);
    for (int i = 1; i <= n; ++i) A[i] -= 'a', B[i] -= 'a';
    for (int i = 0; i < 20; ++i) trs[fa[i] = i] = 1 << i;
    for (int i = 1; i <= n; ++i) {
      if (A[i] ^ B[i]) {
        trs[A[i]] |= 1 << B[i];
        if (int u = find(A[i]), v = find(B[i]); u ^ v) {
          fa[u] = v;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
      if (fa[i] == i) {
        eff.clear();
        for (int j = 0; j < 20; ++j) {
          if (find(j) == i) {
            eff.push_back(j);
          }
        }
        ans += calc(eff);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
