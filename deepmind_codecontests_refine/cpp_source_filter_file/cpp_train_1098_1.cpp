#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 1 << 30;
struct event {
  int x, u, d, op;
} a[100002 * 2];
struct SegmentTree {
  int dat, add;
} t[1000002 * 4];
int n, m, k, i, j, f[1000002], tmp[100002], cnt;
set<pair<int, int> > s;
vector<event> v[1000002];
int read() {
  char c = getchar();
  int w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
int my_comp(const event &a, const event &b) {
  if (a.x != b.x)
    return a.x < b.x;
  else if (a.op != b.op)
    return a.op < b.op;
  else
    return a.d < b.d;
}
void update(int p) { t[p].dat = (t[p * 2].dat + t[p * 2 + 1].dat) % mod; }
void spread(int p) {
  if (t[p].add) {
    t[p * 2].dat = t[p * 2 + 1].dat = 0;
    t[p * 2].add = t[p * 2 + 1].add = 1;
    t[p].add = 0;
  }
}
void change1(int p, int l, int r, int x, int v) {
  if (l == r) {
    t[p].dat = v;
    return;
  }
  int mid = (l + r) / 2;
  spread(p);
  if (x <= mid)
    change1(p * 2, l, mid, x, v);
  else
    change1(p * 2 + 1, mid + 1, r, x, v);
  update(p);
}
void change(int p, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    t[p].dat = 0, t[p].add = 1;
    return;
  }
  int mid = (l + r) / 2;
  spread(p);
  if (ql <= mid) change(p * 2, l, mid, ql, qr);
  if (qr > mid) change(p * 2 + 1, mid + 1, r, ql, qr);
  update(p);
}
int ask(int p, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[p].dat;
  int mid = (l + r) / 2, ans = 0;
  spread(p);
  if (ql <= mid) ans = (ans + ask(p * 2, l, mid, ql, qr)) % mod;
  if (qr > mid) ans += (ans + ask(p * 2 + 1, mid + 1, r, ql, qr)) % mod;
  return ans;
}
int main() {
  n = read();
  m = read();
  k = read();
  for (i = 1; i <= k; i++) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    a[++cnt] = (event){x1, y1, y2, 1};
    a[++cnt] = (event){x2 + 1, y1, y2, -1};
  }
  sort(a + 1, a + cnt + 1, my_comp);
  for (i = 1; i <= cnt; i++) v[a[i].x].push_back(a[i]);
  s.insert(make_pair(0, 0));
  for (i = 1; i <= n; i++) {
    for (j = 0; j < v[i].size(); j++) {
      tmp[j] = 0;
      if (v[i][j].op == 1) {
        int lim;
        set<pair<int, int> >::iterator it =
            s.lower_bound(make_pair(v[i][j].d + 1, inf));
        if (it == s.begin())
          lim = 1;
        else
          it--, lim = (*it).second + 1;
        tmp[j] = ask(1, 1, m + 1, lim, v[i][j].d + 1);
      }
    }
    for (j = 0; j < v[i].size(); j++) {
      if (v[i][j].op == -1)
        s.erase(make_pair(v[i][j].u, v[i][j].d));
      else {
        change(1, 1, m + 1, v[i][j].u, v[i][j].d);
        change1(1, 1, m + 1, v[i][j].d + 1, tmp[j]);
        s.insert(make_pair(v[i][j].u, v[i][j].d));
      }
    }
    if (i == 1) change1(1, 1, m + 1, 1, 1);
  }
  int low = 1;
  for (i = 0; i < v[n + 1].size(); i++) low = max(low, v[n + 1][i].d + 1);
  printf("%d\n", ask(1, 1, m + 1, low, m));
  return 0;
}
