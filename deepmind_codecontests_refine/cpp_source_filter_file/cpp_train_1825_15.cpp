#include <bits/stdc++.h>
using namespace std;
static inline void _mod(long long &x) {
  if (x <= -1000000007 || x >= 1000000007) x %= 1000000007;
  if (x < 0) x += 1000000007;
}
static inline long long madd(long long x, long long y) {
  _mod(x);
  _mod(y);
  x += y;
  _mod(x);
  return x;
}
static inline long long msub(long long x, long long y) {
  _mod(x);
  _mod(y);
  x -= y;
  _mod(x);
  return x;
}
static inline long long mmul(long long x, long long y) {
  _mod(x);
  _mod(y);
  x *= y;
  _mod(x);
  return x;
}
static inline long long mpow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = mmul(ret, x);
    x = mmul(x, x);
  }
  return ret;
}
int ip[200010], p[200010];
struct S {
  vector<pair<long long, long long> > v;
  int h[2][200010], n;
  void eat(int x) {
    for (int i = (0); i < (x); i++) {
      string s;
      int x;
      char c;
      cin >> s;
      sscanf(s.c_str(), "%d-%c", &x, &c);
      if (v.size() && v.back().first == c)
        v.back().second += x;
      else
        v.push_back(pair<long long, long long>(c, x));
    }
    n = v.size();
    h[0][0] = h[1][0] = 0;
    for (int i = (1); i <= (n); i++)
      h[0][i] = madd(h[0][i - 1], mmul(v[i - 1].first, p[i]));
    for (int i = (1); i <= (n); i++)
      h[1][i] = madd(h[1][i - 1], mmul(v[i - 1].second, p[i]));
  }
} s, t;
static inline int ok(int x, int y, int t1, int t2) {
  if (mmul(msub(t.h[0][y + 1], t.h[0][x]), ip[x + 1]) != t1) return 0;
  if (mmul(msub(t.h[1][y + 1], t.h[1][x]), ip[x + 1]) != t2) return 0;
  return 1;
}
int n, m;
int main() {
  p[0] = ip[0] = 1;
  p[1] = 910519;
  ip[1] = mpow(910519, 1000000007 - 2);
  for (int i = (2); i < (200010); i++) p[i] = mmul(p[i - 1], p[1]);
  for (int i = (2); i < (200010); i++) ip[i] = mmul(ip[i - 1], ip[1]);
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  t.eat(n);
  s.eat(m);
  int ans = 0;
  if (s.n == 1) {
    for (int i = (0); i < (t.n); i++)
      if (t.v[i].first == s.v[0].first && t.v[i].second >= s.v[0].second)
        ans += t.v[i].second - s.v[0].second + 1;
  } else if (s.n == 2) {
    for (int i = (0); i < (t.n - 1); i++) {
      if (t.v[i].first == s.v[0].first && t.v[i].second >= s.v[0].second &&
          t.v[i + 1].first == s.v[1].first &&
          t.v[i + 1].second >= s.v[1].second)
        ans++;
    }
  } else {
    int t1, t2;
    t1 = mmul(msub(s.h[0][s.n - 1], s.h[0][1]), ip[2]);
    t2 = mmul(msub(s.h[1][s.n - 1], s.h[1][1]), ip[2]);
    for (int i = (0); i < (t.n - s.n + 1); i++) {
      if (t.v[i].first == s.v[0].first && t.v[i].second >= s.v[0].second &&
          t.v[i + s.n - 1].first == s.v[s.n - 1].first &&
          t.v[i + s.n - 1].second >= s.v[s.n - 1].second) {
        if (ok(i + 1, i + s.n - 2, t1, t2)) {
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
