#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
const long double PI = acos(-1);
bool eq(long double a, long double b) { return fabsl(a - b) <= EPS; }
struct point {
  long double x, y;
  int id;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  point operator+(const point &o) const { return {x + o.x, y + o.y}; }
  point operator-(const point &o) const { return {x - o.x, y - o.y}; }
  point operator*(long double t) const { return {x * t, y * t}; }
  point operator/(long double t) const { return {x / t, y / t}; }
  long double operator*(const point &o) const { return x * o.x + y * o.y; }
  long double operator^(const point &o) const { return x * o.y - y * o.x; }
  bool operator<(const point &o) const {
    if (!eq(x, o.x)) return x < o.x;
    return y > o.y;
  }
  bool operator==(const point &o) const { return eq(x, o.x) and eq(y, o.y); }
};
long double norm(point a) { return sqrt(a * a); }
int quarter(point a) {
  if (a.x > 0 and a.y >= 0) return 3;
  if (a.x <= 0 and a.y > 0) return 0;
  if (a.x < 0 and a.y <= 0) return 1;
  return 2;
}
point c;
bool comp(point a, point b) {
  a = a - c;
  b = b - c;
  int qa = quarter(a);
  int qb = quarter(b);
  if (qa == qb)
    return (a ^ b) > 0;
  else
    return qa < qb;
}
vector<vector<int> > g(MAX, vector<int>());
vector<int> qnt(MAX, 0);
vector<int> ans(MAX, -1);
int dfs(int u, int pai = -1) {
  qnt[u] = 1;
  for (auto v : g[u])
    if (v != pai) qnt[u] += dfs(v, u);
  return qnt[u];
}
void solve(point cu, vector<point> p, int u, int pai = -1) {
  int val = 0;
  assert((int)p.size() == qnt[u] - 1);
  for (auto v : g[u])
    if (v != pai) {
      vector<point> psub;
      point cv = p[val];
      for (int i = val + 1; i < val + qnt[v]; i++) psub.push_back(p[i]);
      psub.push_back(cu);
      val += qnt[v];
      ans[cv.id] = v;
      c = cv;
      sort(psub.begin(), psub.end(), comp);
      int idcu = 0;
      for (int i = 0; i < (int)psub.size(); i++)
        if (psub[i] == cu) idcu = i;
      vector<point> psub2;
      for (int i = idcu + 1; i < (int)psub.size(); i++)
        psub2.push_back(psub[i]);
      for (int i = 0; i < idcu; i++) psub2.push_back(psub[i]);
      solve(cv, psub2, v, u);
    }
  assert(val == (int)p.size());
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].id = i;
  }
  sort(p.begin(), p.end());
  point center = p[0];
  vector<point> psub;
  for (int i = 1; i < n; i++) psub.push_back(p[i]);
  c = center;
  sort(psub.begin(), psub.end(), comp);
  ans[center.id] = 1;
  solve(center, psub, 1);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}
