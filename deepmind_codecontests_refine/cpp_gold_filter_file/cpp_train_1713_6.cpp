#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, a[100005], s[100005];
int st[100005], sz;
bool cmp(long long k1, long long k2, long long k3, long long b1, long long b2,
         long long b3) {
  return (b2 - b1) * (k1 - k3) <= (b3 - b1) * (k1 - k2);
}
vector<pair<int, int> > now;
struct ch {
  vector<int> k, b;
  void build(int l, int r) {
    now.clear();
    for (int i = l; i <= r; ++i) {
      now.push_back(make_pair(-a[i], a[i] * i - s[i]));
    }
    sort((now).begin(), (now).end());
    reverse((now).begin(), (now).end());
    for (int(i) = 0; (i) < (now.size()); ++(i)) {
      if (i + 1 < now.size() && now[i].first == now[i + 1].first) {
        ++i;
      }
      int x = now[i].first, y = now[i].second;
      int last = (int)k.size() - 1;
      while (last >= 1) {
        if (!cmp(x, k[last], k[last - 1], y, b[last], b[last - 1])) {
          break;
        }
        --last;
        k.pop_back();
        b.pop_back();
      }
      k.push_back(x);
      b.push_back(y);
    }
  }
  int f(int id, int x) { return k[id] * x + b[id]; }
  int mn(int x) {
    if (!k.size()) {
      return mod + mod;
    }
    int l = -1, r = (int)k.size() - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (f(m, x) >= f(m + 1, x)) {
        l = m;
      } else {
        r = m;
      }
    }
    return f(l + 1, x);
  }
} t[400005];
void build(int v, int l, int r) {
  t[v].build(l, r);
  if (l == r) {
    return;
  }
  int m = (l + r) / 2;
  build(v + v, l, m);
  build(v + v + 1, m + 1, r);
}
int go(int v, int tl, int tr, int l, int r, int x) {
  if (l > tr || r < tl) {
    return mod + mod;
  }
  if (l <= tl && r >= tr) {
    return t[v].mn(x);
  }
  int tm = (tl + tr) / 2;
  int L = go(v + v, tl, tm, l, r, x);
  int R = go(v + v + 1, tm + 1, tr, l, r, x);
  return min(L, R);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  for (int(i) = 0; (i) < (q); ++(i)) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", go(1, 1, n, y - x + 1, y, y - x) + s[y]);
  }
  return 0;
}
