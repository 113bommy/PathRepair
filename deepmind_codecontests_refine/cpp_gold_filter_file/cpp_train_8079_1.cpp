#include <bits/stdc++.h>
const int N = 5e5 + 5;
using namespace std;
struct point {
  int id, x, y;
  point(int id, int x, int y) : id(id), x(x), y(y) {}
  point() {}
  bool operator<(const point& a) const { return 1LL * x * a.y < 1LL * y * a.x; }
  bool operator==(const point& a) const {
    return 1LL * x * a.y == 1LL * y * a.x;
  }
} p[N];
vector<point> mv[2];
multiset<int> ms[N];
int r, n, type[N], a[N], b[N], cnt, m;
int f[N][2], it[N << 2];
void update(int i, int l, int r, int pos, int val, int v) {
  if (l > pos || pos > r) return;
  if (l == r) {
    if (v)
      ms[l].insert(val);
    else
      ms[l].erase(ms[l].lower_bound(val));
    it[i] = ((ms[l].size()) ? *ms[l].begin() : N);
    return;
  }
  int mid = (l + r) >> 1;
  update(i << 1, l, mid, pos, val, v);
  update(i << 1 | 1, mid + 1, r, pos, val, v);
  it[i] = min(it[i << 1], it[i << 1 | 1]);
}
int get(int i, int l, int r, int L, int R) {
  if (L > r || l > R) return N;
  if (L <= l && r <= R) return it[i];
  int mid = (l + r) >> 1;
  return min(get(i << 1, l, mid, L, R), get(i << 1 | 1, mid + 1, r, L, R));
}
void ins(int a, int b) { update(1, 1, m, b, a, 1); }
void del(int a, int b) { update(1, 1, m, b, a, 0); }
bool cross(point a, point b) {
  a.x -= r;
  b.x += r;
  return 1LL * a.x * b.x + 1LL * a.y * b.y >= 0;
}
bool ck(int a, int b) {
  bool res = true;
  int x = max(f[a][0], f[b][0]), y = min(f[a][1], f[b][1]);
  del(f[a][0], f[a][1]);
  del(f[b][0], f[b][1]);
  if (get(1, 1, m, y, m) <= x) res = false;
  ins(f[a][0], f[a][1]);
  ins(f[b][0], f[b][1]);
  if (f[a][0] > f[b][0]) swap(a, b);
  if (f[a][0] < f[b][0] && f[a][1] < f[b][1]) {
    if (!cross(p[a], p[b])) res = false;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < (N << 2); i++) it[i] = N;
  cin >> r >> n;
  for (int i = 1; i <= n; i++) {
    cin >> type[i] >> a[i];
    if (type[i] != 2) cin >> b[i];
    if (type[i] == 1)
      cnt++, mv[0].push_back(point(cnt, a[i] + r, b[i])),
          mv[1].push_back(point(cnt, a[i] - r, b[i])),
          p[cnt] = point(0, a[i], b[i]);
  }
  sort(mv[0].begin(), mv[0].end());
  sort(mv[1].begin(), mv[1].end());
  for (int i = 0; i < (int)mv[0].size(); i++) {
    if (i == 0 || !(mv[0][i] == mv[0][i - 1])) m++;
    f[mv[0][i].id][0] = m;
  }
  m = 0;
  for (int i = 0; i < (int)mv[1].size(); i++) {
    if (i == 0 || !(mv[1][i] == mv[1][i - 1])) m++;
    f[mv[1][i].id][1] = m;
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (type[i] == 1) cnt++, ins(f[cnt][0], f[cnt][1]);
    if (type[i] == 2) del(f[a[i]][0], f[a[i]][1]);
    if (type[i] == 3) cout << (ck(a[i], b[i]) ? "YES" : "NO") << "\n";
  }
}
