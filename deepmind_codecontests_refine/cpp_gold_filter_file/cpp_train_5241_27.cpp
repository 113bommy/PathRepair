#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
const double EPS_ANG = 1E-13;
const double MAGIC = 0.8;
const int BIG = 100;
const double ANG = PI * 9 / 10;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};
inline bool operator<(const pt &a, const pt &b) {
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
vector<pt> cur;
bool u[2100][2100];
int a[2100][2100], n;
inline bool isin(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }
inline long long vec(pt a, pt b, pt c) {
  return long long(b.x - a.x) * (c.y - a.y) -
         long long(b.y - a.y) * (c.x - a.x);
}
pt glc;
inline long long dist(pt a, pt b) {
  return (a.x - b.x) * long long(a.x - b.x) +
         (a.y - b.y) * long long(a.y - b.y);
}
bool cmp_ang(const pt &a, const pt &b) {
  double a1 = atan2((double)a.y - glc.y, a.x - glc.x);
  double a2 = atan2((double)b.y - glc.y, b.x - glc.x);
  return a1 < a2 - EPS_ANG ||
         abs(a1 - a2) < EPS_ANG && dist(glc, a) < dist(glc, b);
}
inline int sign(long long a) { return a == 0 ? 0 : a > 0 ? +1 : -1; }
vector<pt> convex_hull(vector<pt> &a) {
  if (a.size() <= 2) return a;
  swap(a[0], *min_element(a.begin(), a.end()));
  glc = a[0];
  sort(a.begin() + 1, a.end(), cmp_ang);
  vector<pt> v;
  v.reserve(a.size());
  v.push_back(a[0]);
  v.push_back(a[1]);
  for (int i = (int)(2); i < (int)(a.size()); i++) {
    while (v.size() > 1 && sign(vec(v[v.size() - 2], v.back(), a[i])) < 0)
      v.pop_back();
    v.push_back(a[i]);
  }
  return v;
}
void dfs(int x, int y) {
  u[x][y] = true;
  cur.push_back(pt(x, y));
  for (int dir = 0; dir < (int)(4); dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!isin(nx, ny) || a[nx][ny] == 0 || u[nx][ny]) continue;
    dfs(nx, ny);
  }
}
double angl(pt a, pt b, pt c) {
  double res =
      atan2((double)b.y - a.y, b.x - a.x) - atan2((double)c.y - a.y, c.x - a.x);
  if (res < -EPS) res += PI;
  if (res > PI + EPS) res -= PI;
  return res;
}
vector<pt> hacks(vector<pt> a) {
  cerr << a.size() << endl;
  while (true) {
    bool br = true;
    for (int i = 0; i < (int)(a.size()); i++)
      if (angl(a[i], a[(i + 1) % a.size()], a[(i + a.size() - 1) % a.size()]) <
          0.4) {
        a.erase(a.begin() + i);
        br = false;
        break;
      }
    if (br) break;
  }
  return a;
}
double mass_hacks(vector<pt> a) {
  double cx = 0, cy = 0;
  for (int i = 0; i < (int)(a.size()); i++) {
    cx += a[i].x;
    cy += a[i].y;
  }
  cx /= a.size();
  cy /= a.size();
  double mi = 1E20;
  double ma = -1E20;
  for (int i = 0; i < (int)(a.size()); i++) {
    double di =
        sqrt((a[i].x - cx) * (a[i].x - cx) + (a[i].y - cy) * (a[i].y - cy));
    mi = min(mi, di);
    ma = max(ma, di);
  }
  return ma - mi;
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) scanf("%d", &a[i][j]);
  int c1 = 0, c2 = 0;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (a[i][j] == 1 && !u[i][j]) {
        cur.clear();
        dfs(i, j);
        cur = convex_hull(cur);
        cerr << cur.size() << ' ';
        double di = mass_hacks(cur);
        cerr << di << endl;
        if (di <= MAGIC)
          c2++;
        else
          c1++;
      }
  cout << c2 << ' ' << c1 << endl;
  return 0;
}
