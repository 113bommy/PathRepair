#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000006], V;
struct Node {
  int x, y, w;
  bool operator<(const Node& a) const { return y < a.y; }
} node[500006];
int n;
struct Info {
  long long len, mx, w;
  int p;
  Info() {}
  Info(long long _len, long long _mx, long long _w, int _p) {
    len = _len;
    mx = _mx;
    w = _w;
    p = _p;
  }
  Info operator+(const Info& a) {
    Info ret;
    ret.len = len + a.len;
    ret.w = w + a.w;
    if (a.mx >= a.w + mx - a.len) {
      ret.mx = a.mx;
      ret.p = a.p;
    } else {
      ret.mx = a.w + mx - a.len;
      ret.p = p;
    }
    return ret;
  }
  void pr() { printf("%lld %lld %lld %d\n", len, mx, w, p); }
} info[1000006 << 2];
void build(int p, int l, int r) {
  if (l == r) {
    int len = 0;
    if (l > 1) len = V[l - 1] - V[l - 2];
    info[p] = Info(len, 0, 0, l);
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  info[p] = info[p << 1] + info[p << 1 | 1];
}
void update(int p, int l, int r, int aim, long long w) {
  if (l == r) {
    info[p].w += w;
    info[p].mx += w;
    return;
  }
  int mid = (l + r) >> 1;
  if (aim <= mid)
    update(p << 1, l, mid, aim, w);
  else
    update(p << 1 | 1, mid + 1, r, aim, w);
  info[p] = info[p << 1] + info[p << 1 | 1];
}
Info query(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return info[p];
  }
  int mid = (l + r) >> 1;
  if (L <= mid && R > mid)
    return query(p << 1, l, mid, L, R) + query(p << 1 | 1, mid + 1, r, L, R);
  else if (L <= mid)
    return query(p << 1, l, mid, L, R);
  else if (R > mid)
    return query(p << 1 | 1, mid + 1, r, L, R);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].w);
    if (node[i].x > node[i].y) swap(node[i].x, node[i].y);
    V.push_back(node[i].x);
    V.push_back(node[i].y);
  }
  sort(node + 1, node + n + 1);
  sort(V.begin(), V.end());
  V.resize(unique(V.begin(), V.end()) - V.begin());
  for (int i = 1; i <= n; i++) {
    node[i].x = lower_bound(V.begin(), V.end(), node[i].x) - V.begin();
    node[i].y = lower_bound(V.begin(), V.end(), node[i].y) - V.begin();
    vec[node[i].y].push_back(i);
  }
  int End = V.size();
  build(1, 1, End);
  long long ans = -1e15;
  int ansl, ansr;
  for (int i = 0; i < End; i++) {
    int siz = (int)vec[i].size();
    for (int j = 0; j < siz; j++)
      update(1, 1, End, node[vec[i][j]].x + 1, node[vec[i][j]].w);
    Info tmp = query(1, 1, End, 1, i + 1);
    if (tmp.mx > ans) {
      ans = tmp.mx;
      ansl = V[tmp.p - 1];
      ansr = V[i];
    }
  }
  if (ans < 0) ans = 0, ansl = ansr = 2e9;
  printf("%lld\n%d %d %d %d", ans, ansl, ansl, ansr, ansr);
  return 0;
}
