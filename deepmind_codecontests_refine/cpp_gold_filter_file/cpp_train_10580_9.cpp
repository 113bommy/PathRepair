#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 1e6 + N / 2;
const long double eps = 0.2, eps2 = 0.0001;
const int INF = (int)1e9 + 7, MOD = INF;
const long long LINF = 1e16;
const double PI = acos(-1.0);
long long a[N];
int n, m, vmax;
long long seed;
int rnd() {
  int ret = seed;
  seed = (seed * 7 + 13) % MOD;
  return ret;
}
set<int> ti;
void init() {
  for (int i = 0; i < n; i++) {
    a[i + 1] = rnd() % vmax + 1;
    ti.insert(i + 1);
  }
}
void sep(int e) {
  auto it = ti.lower_bound(e);
  if (*it > e && e != 0) {
    a[e] = a[*it];
    ti.insert(e);
  }
}
long long pw(long long b, long long deg, int mod) {
  long long nd = deg;
  long long y = 1;
  while (nd > 0) {
    if (nd & 1) {
      y *= b;
      y %= mod;
    }
    nd >>= 1;
    b *= b;
    b %= mod;
  }
  return y;
}
int main() {
  scanf("%d%d%I64d%d", &n, &m, &seed, &vmax);
  init();
  for (int s = 0; s < m; s++) {
    int op = rnd() % 4;
    int l = rnd() % n;
    int r = rnd() % n;
    int x;
    if (l > r) swap(l, r);
    if (op == 2) {
      x = (rnd() % (r - l + 1));
      x++;
    } else {
      x = (rnd() % vmax) + 1;
    }
    int y;
    if (op == 3) {
      y = (rnd() % vmax) + 1;
    }
    sep(l);
    sep(r + 1);
    if (op == 0) {
      auto p = ti.lower_bound(l + 1);
      for (auto it = p; it != ti.end(); it++) {
        a[*it] += 1LL * x;
        if (*it >= r + 1) {
          break;
        }
      }
    }
    if (op == 1) {
      auto p1 = ti.lower_bound(l + 1);
      auto p2 = ti.lower_bound(r + 1);
      ti.erase(p1, p2);
      a[r + 1] = x;
    }
    if (op == 2) {
      vector<pair<long long, int>> vals;
      auto p1 = ti.lower_bound(l + 1);
      int lens = 0;
      int nl = l;
      for (auto it = p1; it != ti.end(); it++) {
        vals.push_back(make_pair(a[*it], *it - nl));
        lens += *it - nl;
        nl = *it;
        if (*it >= r + 1) {
          break;
        }
      }
      sort(vals.begin(), vals.end());
      for (int i = 0; i < vals.size(); i++) {
        x -= vals[i].second;
        if (x <= 0) {
          printf("%I64d\n", vals[i].first);
          break;
        }
      }
    }
    if (op == 3) {
      long long sum = 0;
      auto p1 = ti.lower_bound(l + 1);
      for (auto it = p1; it != ti.end(); it++) {
        long long s = *it - l;
        l = *it;
        sum += pw(a[*it] % y, x, y) * 1LL * s;
        sum %= y;
        if (*it >= r + 1) {
          break;
        }
      }
      printf("%I64d\n", sum);
    }
  }
}
