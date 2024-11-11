#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, a[N], p[N], v[N], w, tr[N], st[N], t;
int s[N], pos[N], nxt[N];
long long ans;
char ch[N];
vector<pair<int, int> > wh[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
namespace seg {
int tag[N * 4];
void build(int x, int l, int r) {
  tag[x] = n + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
}
void change(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && rr >= r) {
    tag[x] = min(tag[x], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) change(x + x, l, mid, ll, rr, v);
  if (rr > mid) change(x + x + 1, mid + 1, r, ll, rr, v);
}
void get(int x, int l, int r, int v) {
  v = min(v, tag[x]);
  if (l == r) {
    ans += v - l;
    return;
  }
  int mid = (l + r) >> 1;
  get(x + x, l, mid, v);
  get(x + x + 1, mid + 1, r, v);
}
}  // namespace seg
void prework() {
  n = 1000000;
  for (int i = 2; i <= n; i++) {
    if (!v[i]) v[i] = p[++w] = i;
    for (int j = 1; j <= w; j++) {
      if (p[j] > n / i || p[j] > v[i]) break;
      v[i * p[j]] = p[j];
    }
  }
  for (int i = 1; i <= w; i++) tr[p[i]] = i;
}
signed main() {
  prework();
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) {
    int x = a[i], last = -1, cnt = 0, op = (ch[i] == '/') ? -1 : 1;
    while (x > 1) {
      int now = v[x];
      if (now != last) {
        if (last != -1) wh[tr[last]].emplace_back(i, cnt * op);
        last = now;
        cnt = 0;
      }
      cnt++;
      x /= now;
    }
    if (last != -1) wh[tr[last]].emplace_back(i, cnt * op);
  }
  seg::build(1, 1, n);
  for (int i = 1; i <= w; i++)
    if (!wh[i].empty()) {
      t = 0;
      int m = (int)wh[i].size();
      for (int j = 1; j <= m; j++)
        s[j] = s[j - 1] + wh[i][j - 1].second, pos[j] = wh[i][j - 1].first;
      pos[m + 1] = n + 1;
      for (int j = 0; j <= m; j++) {
        while (t && s[j] < s[st[t]]) nxt[st[t--]] = j;
        st[++t] = j;
      }
      while (t) nxt[st[t--]] = m + 1;
      for (int j = 1; j <= m; j++) {
        if (ch[pos[j]] == '/')
          seg::change(1, 1, n, pos[j - 1] + 1, pos[j], pos[j]);
        else
          seg::change(1, 1, n, pos[j - 1] + 1, pos[j], pos[nxt[j - 1]]);
      }
    }
  seg::get(1, 1, n, 0x3f3f3f3f);
  printf("%lld\n", ans);
}
