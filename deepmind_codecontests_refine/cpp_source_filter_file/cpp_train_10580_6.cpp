#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int mul(long long int a, long long int b, long long int m) {
  return a * b >= m ? a * b % m : a * b;
}
long long int mod = 1e9 + 7;
long long int mpow(long long int b, long long int exp, long long int m) {
  long long int r = 1;
  while (exp) {
    if (exp & 1) r = mul(r, b, m);
    b = mul(b, b, m);
    exp /= 2;
  }
  return r;
}
long long int seed;
long long int rnd() {
  int res = seed;
  seed = (seed * 7 + 13) % mod;
  return res;
}
int main() {
  map<int, long long int> a;
  int n, m, vmax;
  cin >> n >> m >> seed >> vmax;
  for (int i = 1; i <= n; ++i) a.insert(a.end(), {i, rnd() % vmax + 1});
  a.insert(a.end(), {n + 1, 0});
  while (m--) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    long long int x, y;
    if (l > r) swap(l, r);
    if (op == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if (op == 4) y = rnd() % vmax + 1;
    auto itl = --(a.upper_bound(l));
    if (itl->first != l) {
      a[l] = itl->second;
      ++itl;
    }
    auto itr = --(a.upper_bound(r + 1));
    if (itr->first != r + 1) {
      a[r + 1] = itr->second;
      ++itr;
    }
    vector<pair<long long int, long long int> > v;
    long long int res = 0;
    if (op == 1) {
      while (itl != itr) {
        --itr;
        itr->second += x;
      }
    } else if (op == 2) {
      while (itl != itr) {
        a.erase(itl++);
      }
      a[l] = x;
    } else if (op == 3) {
      for (int ub; itl != itr;)
        ub = (itr--)->first, v.push_back({itr->second, ub - itr->first});
      sort(v.begin(), v.end());
      for (int i = 0, cnt = 0;; ++i)
        if (x <= (cnt += v[i].second)) {
          cout << v[i].first << "\n";
          break;
        }
    } else {
      for (long long int ub; itl != itr;) {
        ub = (itr--)->first;
        res += (mpow(itr->second % vmax, x, y) * (ub - itr->first)) % y;
        res %= y;
      }
      cout << res << "\n";
    }
  }
  return 0;
}
