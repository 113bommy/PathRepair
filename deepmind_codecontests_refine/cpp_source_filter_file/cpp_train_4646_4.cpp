#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000404;
const long long MOD = 1000000007ll;
const long double PI = acos(-1.0);
const long long INF = 1000000000000000404ll;
const long double EPS = 1e-9;
template <typename t1, typename t2>
inline void upmax(t1 &a, t2 b) {
  a = max(a, (t1)b);
}
template <typename t1, typename t2>
inline void upmin(t1 &a, t2 b) {
  a = min(a, (t1)b);
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
inline bool pal(string &x) {
  int n = (int)x.length();
  for (int i = 0; i < n / 2; i++) {
    if (x[i] != x[n - i - 1]) return 0;
  }
  return 1;
}
template <typename T>
inline void rev(T &x) {
  int n = (int((x.size())));
  for (int i = 0; i < n / 2; i++) swap(x[i], x[n - i - 1]);
}
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
class compare {
 public:
  bool operator()(const int a, const int b) const { return 1; }
};
int SQ = 400;
struct node {
  node *l, *r;
  int add, minn;
  node() : l(NULL), add(0), minn(0), r(NULL){};
} * t;
void update(int l, int r, node *v, int tl, int tr) {
  if (l > tr || r < tl) return;
  if (l <= tl && tr <= r) {
    v->add++;
    v->minn++;
    return;
  }
  int tm = (tl + tr) >> 1;
  if (!v->l) v->l = new node();
  if (!v->r) v->r = new node();
  if (v->add) {
    v->l->add += v->add;
    v->l->minn += v->add;
    v->r->add += v->add;
    v->r->minn += v->add;
    v->add = 0;
  }
  update(l, r, v->l, tl, tm);
  update(l, r, v->r, tm + 1, tr);
  v->minn = min(v->l->minn, v->r->minn);
}
int getmin(int l, int r, node *v, int tl, int tr) {
  if (l > tr || r < tl) return inf;
  if (l <= tl && tr <= r) {
    return v->minn;
  }
  int tm = (tl + tr) >> 1;
  if (!v->l) v->l = new node();
  if (!v->r) v->r = new node();
  if (v->add) {
    v->l->add += v->add;
    v->l->minn += v->add;
    v->r->add += v->add;
    v->r->minn += v->add;
    v->add = 0;
  }
  return min(getmin(l, r, v->l, tl, tm), getmin(l, r, v->r, tm + 1, tr));
}
int l[211111], r[211111];
void solve() {
  t = new node();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    update(l[i], r[i], t, 1, 1e9);
  }
  for (int i = 0; i < n; i++) {
    if (getmin(l[i], r[i], t, 1, 1e9) != 1) {
      cout << i + 1;
      return;
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  };
  getchar();
  getchar();
  return 0;
}
