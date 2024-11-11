#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
long long n, m, seed, vmax;
map<long long, long long> q;
long long binpow(long long n, long long p, long long r) {
  if (p == 0) {
    return 1 % r;
  }
  if (p == 1) {
    return n % r;
  }
  long long ans = binpow(n, p / 2, r);
  ans = ans * ans % r;
  if (p % 2 == 1) {
    ans = ans * n % r;
  }
  return ans;
}
long long rnd() {
  long long ans = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ans;
}
inline void solve() {
  for (long long i = 1; i <= n; i++) {
    q[i] = rnd() % vmax + 1;
  }
  q[n + 1] = 0;
  for (long long i = 0; i < m; i++) {
    long long op = rnd() % 4 + 1;
    long long l = rnd() % n + 1;
    long long r = rnd() % n + 1;
    long long x = 0, y = 0;
    if (l > r) {
      swap(l, r);
    }
    if (op == 3) {
      x = rnd() % (r - l + 1) + 1;
    } else {
      x = rnd() % vmax + 1;
    }
    if (op == 4) {
      y = rnd() % vmax + 1;
    }
    auto itl = q.upper_bound(l);
    --itl;
    if (itl->first != l) {
      q[l] = itl->second;
      ++itl;
    }
    auto itr = q.upper_bound(r + 1);
    --itr;
    if (itr->first != r + 1) {
      q[r + 1] = itr->second;
      ++itr;
    }
    if (op == 1) {
      for (auto& iter = itl; iter != itr; iter++) {
        iter->second += x;
      }
    } else if (op == 2) {
      for (auto& iter = itl; iter != itr;) {
        iter = q.erase(iter);
      }
      q[l] = x;
    } else if (op == 3) {
      vector<pair<long long, long long> > v;
      for (auto& iter = itl; iter != itr; iter++) {
        long long n = next(iter)->first - iter->first;
        v.push_back({iter->second, n});
      }
      long long cur = 0;
      sort((v).begin(), (v).end());
      for (pair<long long, long long> p : v) {
        if (cur + p.second >= x) {
          cout << p.first << "\n";
          break;
        }
        cur += p.second;
      }
    } else if (op == 4) {
      long long ans = 0;
      for (auto& iter = itl; iter != itr; iter++) {
        long long n = next(iter)->first - iter->first;
        long long val = binpow(iter->second, x, y);
        ans += n % y * val % y;
        ans %= y;
      }
      cout << ans << "\n";
    }
  }
}
inline void read() { cin >> n >> m >> seed >> vmax; }
