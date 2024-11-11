#include <bits/stdc++.h>
using namespace std;
int const MAX = 200 * 1000 + 41;
long double const EPS = 1e-12;
bool eq(long double a, long double b) { return abs(a - b) < EPS; }
bool leq(long double a, long double b) { return (a < b || eq(a, b)); }
int n, w;
int x[MAX];
int v[MAX];
pair<long double, long double> a[MAX];
pair<int, int> b[MAX];
int const ADD = 0;
int const ASK = 1;
struct Event {
  int y, s, t;
  Event(){};
  Event(int y, int s, int t) : y(y), s(s), t(t){};
  bool operator<(const Event &a) const {
    if (t != a.t) return t < a.t;
    return y < a.y;
  };
};
vector<Event> e[MAX];
int gethash(vector<long double> &v, long double x) {
  int l = -1;
  int r = (int)v.size();
  while (r - l > 1) {
    int h = (l + r) / 2;
    if (leq(v[h], x)) {
      l = h;
    } else {
      r = h;
    }
  }
  return l;
}
void init() {
  vector<long double> tmp;
  for (int i = 1; i <= n; i++) {
    long double l = (long double)v[i] / x[i] - (long double)w / x[i];
    long double r = (long double)v[i] / x[i] + (long double)w / x[i];
    a[i] = make_pair(l, r);
    tmp.push_back(l);
    tmp.push_back(r);
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 1; i <= n; i++) {
    b[i] = make_pair(gethash(tmp, a[i].first), gethash(tmp, a[i].second));
  }
  for (int i = 1; i <= n; i++) {
    int x = b[i].first;
    int y = b[i].second;
    e[x].push_back(Event(y, 41, ADD));
    e[x].push_back(Event(y, -1, ASK));
    e[MAX - 1].push_back(Event(y, 1, ASK));
  }
}
namespace Fen {
int F[MAX];
void upd(int x, int v) {
  while (x < MAX) {
    F[x] += v;
    x |= (x + 1);
  }
}
int get(int x) {
  int res = 0;
  while (x >= 0) {
    res += F[x];
    x = (x & (x + 1)) - 1;
  }
  return res;
}
};  // namespace Fen
long long ans;
void solve() {
  init();
  for (int i = 1; i <= n; i++) {
    while (false) {
    };
  }
  for (int i = 0; i <= MAX - 1; i++) {
    sort(e[i].begin(), e[i].end());
    for (Event z : e[i]) {
      if (z.t == ADD) {
        Fen::upd(z.y, 1);
      } else {
        int q = Fen::get(z.y);
        ans += q * z.s;
      }
    }
  }
  unordered_map<int, int> ql;
  for (int i = 1; i <= n; i++) {
    ql[b[i].first]++;
    ans += ql[b[i].first] - 1;
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d %d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &v[i]);
  }
  solve();
  return 0;
}
