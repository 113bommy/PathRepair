#include <bits/stdc++.h>
using namespace std;
inline long long Get() {
  char ch;
  long long Num, Sign = 0;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') Sign ^= 1;
  Num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    Num = (Num << 3) + (Num << 1) + ch - '0';
  return Sign ? -Num : Num;
}
const int N = 5e5 + 5;
const long long inf = 1e16;
int n, m;
long long a[N], b[N];
long long mn[N << 2], tag[N << 2];
pair<long long, int> mnA[N << 2], mnB[N << 2], vA[N << 2], vB[N << 2];
pair<long long, pair<int, int> > p0[N << 2], p1[N << 2], v1[N << 2];
void down(int k) {
  if (tag[k]) {
    mn[k << 1] += tag[k], mn[k << 1 | 1] += tag[k];
    tag[k << 1] += tag[k], tag[k << 1 | 1] += tag[k];
    tag[k] = 0;
  }
}
void up(int k) {
  int l = k << 1, r = k << 1 | 1;
  p0[k] = min(min(p0[l], p0[r]),
              make_pair(mnA[l].first + mnB[r].first,
                        make_pair(mnA[l].second, mnB[r].second)));
  p1[k] = min(min(p1[l], p1[r]),
              make_pair(mnA[r].first + mnB[l].first,
                        make_pair(mnA[r].second, mnB[l].second)));
  v1[k] = min(v1[l], v1[r]);
  mnA[k] = min(mnA[l], mnA[r]), mnB[k] = min(mnB[l], mnB[r]);
  if (mn[l] < mn[r]) {
    mn[k] = mn[l];
    v1[k] = min(min(v1[k], p1[r]),
                make_pair(mnA[r].first + vB[l].first,
                          make_pair(mnA[r].second, vB[l].second)));
    vA[k] = vA[l], vB[k] = min(vB[l], mnB[r]);
  }
  if (mn[l] > mn[r]) {
    mn[k] = mn[r];
    v1[k] = min(min(v1[k], p1[l]),
                make_pair(vA[r].first + mnB[l].first,
                          make_pair(vA[r].second, mnB[l].second)));
    vA[k] = min(mnA[l], vA[r]), vB[k] = vB[r];
  }
  if (mn[l] == mn[r]) {
    mn[k] = mn[l];
    v1[k] = min(v1[k], make_pair(vA[r].first + vB[l].first,
                                 make_pair(vA[r].second, vB[l].second)));
    vA[k] = vA[l], vB[k] = vB[r];
  }
}
void build(int k, int l, int r) {
  if (l == r) {
    p0[k] = p1[k] = make_pair(a[l] + b[l], make_pair(l, l));
    v1[k] = make_pair(inf * 2, make_pair(0, 0));
    vA[k] = make_pair(inf, l), vB[k] = make_pair(inf, 0);
    mnA[k] = make_pair(a[l], l), mnB[k] = make_pair(b[l], l);
    return;
  }
  int mid = l + r >> 1;
  build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
  up(k);
}
void modify0(int k, int l, int r, int x, int y, int val) {
  if (x <= l && r <= y) {
    mn[k] += val, tag[k] += val;
    return;
  }
  int mid = l + r >> 1;
  down(k);
  if (x <= mid) modify0(k << 1, l, mid, x, y, val);
  if (y > mid) modify0(k << 1 | 1, mid + 1, r, x, y, val);
  up(k);
  return;
}
void modify1(int k, int l, int r, int pos) {
  if (l == r) {
    p0[k] = p1[k] = make_pair(a[l] + b[l], make_pair(l, l));
    v1[k] = make_pair(inf * 2, make_pair(0, 0));
    vA[k] = make_pair(inf, 0), vB[k] = make_pair(inf, 0);
    mnA[k] = make_pair(a[l], l), mnB[k] = make_pair(b[l], l);
    return;
  }
  int mid = l + r >> 1;
  down(k);
  if (pos <= mid)
    modify1(k << 1, l, mid, pos);
  else
    modify1(k << 1 | 1, mid + 1, r, pos);
  up(k);
  return;
}
int main() {
  n = Get(), m = Get();
  a[0] = inf;
  for (int i = 1; i <= n; ++i) a[i] = Get();
  b[0] = inf;
  for (int i = 1; i <= n; ++i) b[i] = Get();
  build(1, 0, n);
  long long ans = 0;
  while (m--) {
    pair<long long, pair<int, int> > res = min(p0[1], v1[1]);
    ans += res.first;
    if (res.second.first < res.second.second)
      modify0(1, 0, n, res.second.first, res.second.second - 1, 1);
    if (res.second.second < res.second.first)
      modify0(1, 0, n, res.second.second, res.second.first - 1, -1);
    a[res.second.first] = inf, modify1(1, 0, n, res.second.first);
    b[res.second.second] = inf, modify1(1, 0, n, res.second.second);
  }
  printf("%lld\n", ans);
}
