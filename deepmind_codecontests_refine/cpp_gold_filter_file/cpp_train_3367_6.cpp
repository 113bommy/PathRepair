#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 100002;
const int K_MAX = 100002;
struct Point {
  int x, y;
  int yn;
  int index;
};
bool operator<(const Point &a, const Point &b) {
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
struct Element {
  int val;
  int index;
  int type;
};
bool operator<(const Element &a, const Element &b) { return a.val < b.val; }
int n, k;
Point d[N_MAX], m[K_MAX];
Element vn[N_MAX * 4 + K_MAX];
void ynorm() {
  for (int i = 1; i <= n; i++) vn[i] = Element{d[i].y, i, 1};
  for (int i = 1; i <= k; i++) vn[n + i] = Element{m[i].y, i, 2};
  sort(vn + 1, vn + n + k + 1);
  int nval = 0;
  for (int i = 1; i <= n + k; i++) {
    if (i == 1 || vn[i].val > vn[i - 1].val) nval++;
    if (vn[i].type == 1)
      d[vn[i].index].yn = nval;
    else
      m[vn[i].index].yn = nval;
  }
}
int dmin[N_MAX];
int BIT[N_MAX + K_MAX];
void update(int pos, int val) {
  for (int i = pos; i <= n + k; i += i & -i) BIT[i] = min(BIT[i], val);
}
int query(int pos) {
  int ans = INT_MAX;
  for (int i = pos; i >= 1; i -= i & -i) ans = min(ans, BIT[i]);
  return ans;
}
void fdmin() {
  ynorm();
  sort(d + 1, d + n + 1);
  sort(m + 1, m + k + 1);
  for (int i = 1; i <= n + k; i++) BIT[i] = INT_MAX;
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    while (pos < k && m[pos + 1].x <= d[i].x) {
      pos++;
      update(m[pos].yn, -m[pos].x - m[pos].y);
    }
    int val = query(d[i].yn);
    if (val != INT_MAX)
      dmin[d[i].index] = min(dmin[d[i].index], val + d[i].x + d[i].y);
  }
}
bool cmpdmin(const Point &a, const Point &b) {
  return dmin[a.index] < dmin[b.index];
}
Point asuff[N_MAX], bsuff[N_MAX];
Point q[N_MAX * 4];
int cnt[N_MAX * 4];
void ynormq() {
  for (int i = 1; i <= k; i++) vn[i] = Element{m[i].y, i, 2};
  for (int i = 1; i <= n * 4; i++) vn[k + i] = Element{q[i].y, i, 3};
  sort(vn + 1, vn + n * 4 + k + 1);
  int nval = 0;
  for (int i = 1; i <= n * 4 + k; i++) {
    if (i == 1 || vn[i].val > vn[i - 1].val) nval++;
    if (vn[i].type == 2)
      m[vn[i].index].yn = nval;
    else
      q[vn[i].index].yn = nval;
  }
}
int BIT1[N_MAX * 4 + K_MAX];
void update1(int pos) {
  for (int i = pos; i <= n * 4 + k; i += i & -i) BIT1[i]++;
}
int query1(int pos) {
  int ans = 0;
  for (int i = pos; i >= 1; i -= i & -i) ans += BIT1[i];
  return ans;
}
void ansq() {
  ynormq();
  sort(m + 1, m + k + 1);
  sort(q + 1, q + n * 4 + 1);
  for (int i = 1; i <= n * 4 + k; i++) BIT1[i] = 0;
  int pos = 0;
  for (int i = 1; i <= n * 4; i++) {
    while (pos < k && m[pos + 1].x <= q[i].x) {
      pos++;
      update1(m[pos].yn);
    }
    int val = query1(q[i].yn);
    cnt[q[i].index] += val;
  }
}
bool cmpindex(const Point &a, const Point &b) { return a.index < b.index; }
bool ftest(int mxd) {
  sort(d + 1, d + n + 1, cmpdmin);
  asuff[n + 1] = Point{INT_MIN, INT_MIN};
  bsuff[n + 1] = Point{INT_MAX, INT_MAX};
  for (int i = n; i >= 1; i--) {
    asuff[i] = asuff[i + 1];
    bsuff[i] = bsuff[i + 1];
    Point a, b;
    a.x = d[i].x - mxd;
    a.y = d[i].y - mxd;
    b.x = d[i].x + mxd;
    b.y = d[i].y + mxd;
    asuff[i].x = max(asuff[i].x, a.x);
    asuff[i].y = max(asuff[i].y, a.y);
    bsuff[i].x = min(bsuff[i].x, b.x);
    bsuff[i].y = min(bsuff[i].y, b.y);
  }
  if (asuff[1].x <= bsuff[1].x && asuff[1].y <= bsuff[1].y) return true;
  for (int i = 1; i <= n; i++) {
    if (asuff[i].x <= bsuff[i].x && asuff[i].y <= bsuff[i].y) {
      asuff[i].x -= (mxd - dmin[d[i - 1].index]);
      asuff[i].y -= (mxd - dmin[d[i - 1].index]);
      bsuff[i].x += (mxd - dmin[d[i - 1].index]);
      bsuff[i].y += (mxd - dmin[d[i - 1].index]);
    }
    q[(i - 1) * 4 + 1] = Point{bsuff[i].x, bsuff[i].y};
    q[(i - 1) * 4 + 2] = Point{bsuff[i].x, asuff[i].y - 1};
    q[(i - 1) * 4 + 3] = Point{asuff[i].x - 1, bsuff[i].y};
    q[(i - 1) * 4 + 4] = Point{asuff[i].x - 1, asuff[i].y - 1};
    q[(i - 1) * 4 + 1].index = (i - 1) * 4 + 1;
    q[(i - 1) * 4 + 2].index = (i - 1) * 4 + 2;
    q[(i - 1) * 4 + 3].index = (i - 1) * 4 + 3;
    q[(i - 1) * 4 + 4].index = (i - 1) * 4 + 4;
  }
  for (int i = 1; i <= n * 4; i++) cnt[i] = 0;
  ansq();
  sort(q + 1, q + n * 4 + 1, cmpindex);
  for (int i = 1; i <= n; i++)
    if (dmin[d[i - 1].index] <= mxd && asuff[i].x <= bsuff[i].x &&
        asuff[i].y <= bsuff[i].y) {
      int cnti = 0;
      cnti += cnt[(i - 1) * 4 + 1];
      cnti -= cnt[(i - 1) * 4 + 2];
      cnti -= cnt[(i - 1) * 4 + 3];
      cnti += cnt[(i - 1) * 4 + 4];
      if (cnti > 0) return true;
    }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> d[i].x >> d[i].y;
    d[i].index = i;
  }
  for (int i = 1; i <= k; i++) {
    cin >> m[i].x >> m[i].y;
    m[i].index = i;
  }
  for (int i = 1; i <= n; i++) dmin[i] = INT_MAX;
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      fdmin();
      for (int i = 1; i <= n; i++) d[i].y = -d[i].y;
      for (int i = 1; i <= k; i++) m[i].y = -m[i].y;
    }
    for (int i = 1; i <= n; i++) d[i].x = -d[i].x;
    for (int i = 1; i <= k; i++) m[i].x = -m[i].x;
  }
  for (int i = 1; i <= n; i++) {
    int x, y;
    x = d[i].x;
    y = d[i].y;
    d[i].x = y + x;
    d[i].y = y - x;
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    x = m[i].x;
    y = m[i].y;
    m[i].x = y + x;
    m[i].y = y - x;
  }
  int l = 0, r = 200000000;
  while (l < r) {
    int mid = ((l + r) >> 1);
    if (ftest(mid) == false)
      l = mid + 1;
    else
      r = mid;
  }
  cout << l << "\n";
  return 0;
}
