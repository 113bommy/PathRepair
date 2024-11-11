#include <bits/stdc++.h>
using namespace std;
long long pw(long long b, long long n, long long m, long long a = 1) {
  while (n) {
    if (n & 1) a = a * b % m;
    b = b * b % m;
    n >>= 1;
  }
  return a % m;
}
struct meow {
  long long l, r, v;
};
bool operator<(const meow &a, const meow &b) {
  return tie(a.l, a.r, a.v) < tie(b.l, b.r, b.v);
}
long long a[100005];
int32_t main() {
  long long n, m;
  long long seed, vmax;
  cin >> n >> m >> seed >> vmax;
  auto rand = [&]() {
    long long rt = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return rt;
  };
  for (long long i = 1; i <= n; ++i) a[i] = rand() % vmax + 1;
  set<meow> st;
  for (long long i = 1, j; i <= n; i = j) {
    for (j = i + 1; j <= n && a[j] == a[i]; ++j)
      ;
    st.insert({i, j - 1, a[i]});
  }
  for (long long i = 1; i <= m; ++i) {
    long long op = rand() % 4 + 1;
    long long l = rand() % n + 1, r = rand() % n + 1;
    if (l > r) swap(l, r);
    if (op == 1) {
      long long x = rand() % vmax + 1;
      while (l <= r) {
        auto it = st.upper_bound({l, n + 1, 0});
        --it;
        auto p = *it;
        st.erase(it);
        if (p.l < l) {
          auto cp = p;
          cp.r = l - 1;
          st.insert(cp);
          p.l = l;
        }
        if (p.r > r) {
          auto cp = p;
          cp.l = r + 1;
          st.insert(cp);
          p.r = r;
        }
        p.v += x;
        st.insert(p);
        l = p.r + 1;
      }
    } else if (op == 2) {
      long long x = rand() % vmax + 1;
      long long L = l;
      while (l <= r) {
        auto it = st.upper_bound({l, n + 1, 0});
        --it;
        auto p = *it;
        st.erase(it);
        if (p.l < l) {
          auto cp = p;
          cp.r = l - 1;
          st.insert(cp);
          p.l = l;
        }
        if (p.r > r) {
          auto cp = p;
          cp.l = r + 1;
          st.insert(cp);
          p.r = r;
        }
        l = p.r + 1;
      }
      st.insert({L, r, x});
    } else if (op == 3) {
      long long x = rand() % (r - l + 1) + 1;
      auto it = st.upper_bound({l, n + 1, 0});
      --it;
      set<pair<long long, long long>> nums;
      while (it != st.end() && it->l <= r) {
        long long len = min(it->r, r) - max(it->l, l) + 1;
        nums.insert({it->v, len});
        ++it;
      }
      for (auto i : nums) {
        x -= i.second;
        if (x <= 0) {
          cout << i.first << '\n';
          break;
        }
      }
    } else if (op == 4) {
      long long x = rand() % vmax + 1;
      long long y = rand() % vmax + 1;
      auto it = st.upper_bound({l, n + 1, 0});
      --it;
      long long ans = 0;
      while (it != st.end() && it->l <= r) {
        long long len = min(it->r, r) - max(it->l, l) + 1;
        ans += pw(it->v % y, x, y) * len % y;
        ++it;
      }
      cout << ans % y << '\n';
    }
  }
}
