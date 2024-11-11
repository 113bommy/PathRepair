#include <bits/stdc++.h>
const int maxn = 300005, maxm = 300005;
const int INF = 2e9;
int ret[maxn];
int n;
int t[maxn << 1];
void upd(int l, int r, int x) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) t[l] = std::min(t[l], x), l++;
    if (r & 1) --r, t[r] = std::min(t[r], x);
  }
}
int find_max(int p) {
  int ans = INF;
  for (p += n; p > 0; p >>= 1) ans = std::min(ans, t[p]);
  return ans;
}
int t2[maxn << 1];
void build() {
  for (int i = 0; i < n; i++) t2[i + n] = ret[i];
  for (int i = n - 1; i > 0; i--) t2[i] = std::max(t2[i << 1], t2[i << 1 | 1]);
}
void upd(int p, int val) {
  for (t2[p += n] = val; p > 1; p >>= 1)
    t2[p >> 1] = std::max(t2[p], t2[p ^ 1]);
}
int find_max(int l, int r) {
  int ans = -INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = std::max(ans, t2[l++]);
    if (r & 1) ans = std::max(ans, t2[--r]);
  }
  return ans;
}
int type[maxm], a[maxm], b[maxm], c[maxm];
int m;
void read() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n << 1; i++) t[i] = INF;
  for (int i = 0; i < n; i++) ret[i] = INF + 1;
  for (int i = 0; i < m; i++) {
    scanf("%d", &type[i]);
    if (type[i] == 1) {
      scanf("%d %d %d", &a[i], &b[i], &c[i]);
      a[i]--, b[i]--;
      upd(a[i], b[i] + 1, c[i]);
    } else {
      scanf("%d %d", &a[i], &b[i]);
      a[i]--;
      if (ret[a[i]] == INF + 1) ret[a[i]] = find_max(a[i]);
    }
  }
  for (int i = 0; i < n; i++)
    if (ret[i] == INF + 1) ret[i] = find_max(i);
}
std::map<int, int> mp;
void solve() {
  build();
  for (int i = 0; i < m; i++) {
    if (type[i] == 1) {
      if (find_max(a[i], b[i] + 1) != c[i]) {
        printf("NO\n");
        return;
      }
    } else
      upd(a[i], b[i]);
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) mp[ret[i]]++;
  if (mp[INF] > 1) {
    for (int i = 0; i < n; i++)
      if (ret[i] == INF) {
        ret[i] = 1 << 29, mp[INF]--;
        if (mp[INF] == 0) ret[i] = (1 << 29) - 1;
      }
    for (int i = 0; i < n; i++) printf("%d%c", ret[i], " \n"[i == n - 1]);
    return;
  }
  int or_ret = 0;
  for (int i = 0; i < n; i++) {
    if (ret[i] == 0 || ret[i] == INF) continue;
    mp[ret[i]]--;
    if (mp[ret[i]]) {
      int tmp = ret[i], pow = 0;
      while (tmp) pow++, tmp >>= 1;
      ret[i] = (1 << (pow - 1)) - 1;
    }
    or_ret |= ret[i];
  }
  int tobe = 0;
  for (int cur = 29; cur >= 0; cur--) {
    if (or_ret & (1 << cur)) continue;
    if (tobe + (1 << cur) > 1e9) continue;
    tobe += (1 << cur);
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", ret[i] == INF ? tobe : ret[i], " \n"[i == n - 1]);
}
int main() {
  read();
  solve();
}
