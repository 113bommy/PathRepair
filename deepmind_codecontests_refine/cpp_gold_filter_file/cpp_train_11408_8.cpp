#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int INF = 1e9 + 10;
struct Q {
  int l, r, id;
  bool operator<(const Q &A) const { return (r < A.r); }
};
vector<Q> v[333];
int pre[100010], ts, m, tmp[100010], now[100010], a[100010], f[100010],
    dp[333][100010], nxt[100010], ans[300010], n, bs, B, bl[100010];
void clear() {
  for (int i = 1; i <= n + 1; i++) pre[i] = i - 1;
  for (int i = 0; i <= n; i++) nxt[i] = i + 1;
}
void del(int x) {
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
}
int ins(int x) {
  int t = INF;
  if (pre[x] >= 1) t = min(t, tmp[x] - tmp[pre[x]]);
  if (nxt[x] <= n) t = min(t, tmp[nxt[x]] - tmp[x]);
  nxt[pre[x]] = x;
  pre[nxt[x]] = x;
  return t;
}
int main() {
  scanf("%d", &n);
  bs = sqrt(n);
  for (int i = 1; i <= n; i++) bl[i] = (i - 1) / bs + 1;
  B = bl[n];
  for (int i = 1; i <= n; i++) getint(a[i]), tmp[++ts] = a[i];
  for (int i = 1; i <= n; i++) dp[1][i] = INF;
  for (int j = 2; j <= bs; j++)
    for (int i = 1; i <= n - j + 1; i++)
      dp[j][i] =
          min(min(dp[j - 1][i], dp[j - 1][i + 1]), abs(a[i] - a[i + j - 1]));
  sort(tmp + 1, tmp + ts + 1);
  for (int i = 1; i <= n; i++) now[i] = i;
  for (int i = 1; i <= n; i++) {
    int t = lower_bound(tmp + 1, tmp + ts + 1, a[i]) - tmp;
    a[i] = now[t];
    ++now[t];
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    Q x;
    getint(x.l), getint(x.r);
    x.id = i;
    if (x.r - x.l + 1 <= bs)
      ans[i] = dp[x.r - x.l + 1][x.l];
    else
      v[bl[x.l]].push_back(x);
  }
  for (int i = 1; i <= B; i++) {
    if (v[i].empty()) continue;
    sort(v[i].begin(), v[i].end());
    clear();
    int L = (i - 1) * bs + 1, R = min(i * bs, n);
    for (int j = 1; j <= R - 1; j++) del(a[j]);
    for (int j = n; j >= R + 1; j--) del(a[j]);
    f[R] = INF;
    for (int j = R + 1; j <= n; j++) f[j] = min(f[j - 1], ins(a[j]));
    for (int j = R - 1; j >= L; j--) ins(a[j]);
    for (int j = v[i].size() - 1, k = n; j >= 0; --j) {
      Q x = v[i][j];
      while (k > x.r) del(a[k]), --k;
      int cur = f[k];
      for (int j = L; j <= R - 1; j++) del(a[j]);
      for (int j = R - 1; j >= x.l; j--) cur = min(cur, ins(a[j]));
      for (int j = x.l - 1; j >= L; j--) ins(a[j]);
      ans[x.id] = cur;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
