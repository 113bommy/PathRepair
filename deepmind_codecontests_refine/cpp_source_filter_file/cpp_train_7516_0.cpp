#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const long long N = 51;
long long sum(long long x, long long y) { return x + min(y, INF - x); }
long long mul(long long x, long long y) { return x * min(y, INF / x + 1); }
long long n, k;
long long get1(long long x) {
  static vector<long long> arr = {1, 1, 1};
  while (arr.size() <= x) {
    arr.push_back(mul(arr.back(), arr.size() - 2));
  }
  return arr[x];
}
long long get2(long long x) {
  static vector<long long> arr = {1};
  while (arr.size() <= x) {
    long long cur = 0;
    for (long long y = 1; y <= arr.size(); ++y) {
      cur = sum(cur, mul(get1(y), arr[arr.size() - y]));
    }
    arr.push_back(cur);
  }
  return arr[x];
}
struct DSU {
  vector<long long> par, sz;
  long long find(long long x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool check(long long x, long long y) { return find(x) == find(y); }
  void join(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (sz[x] > sz[y]) {
        swap(x, y);
      }
      par[x] = y;
      sz[y] += sz[x];
    }
  }
  DSU() {}
  DSU(long long n) : par(n), sz(n, 1) {
    for (long long x = 0; x < n; ++x) {
      par[x] = x;
    }
  }
};
void f(long long x, long long shift, long long k) {
  set<long long> r;
  DSU dsu(x);
  for (long long i = 0; i < x; ++i) {
    long long nxt = -1;
    if (i == 0) {
      nxt = x - 1;
    } else {
      do {
        if (nxt == -1) {
          nxt = 0;
        } else {
          k -= get1(x - i + 1);
          ++nxt;
        }
        while (r.count(nxt) || (dsu.check(i, nxt) && i != x - 1)) {
          ++nxt;
        }
      } while (k > get1(x - i - 1));
    }
    r.insert(nxt);
    dsu.join(nxt, i);
    cout << nxt + shift + 1 << ' ';
  }
}
bool ok(vector<long long> perm) {
  for (long long i = 0; i < perm.size();) {
    DSU dsu(n);
    if (perm[i] == i) {
      ++i;
      continue;
    }
    if (perm[i] < i) {
      return false;
    }
    for (long long j = i; j <= perm[i]; ++j) {
      if (perm[j] < i || perm[j] > perm[i] ||
          (dsu.check(j, perm[j]) && j != perm[i])) {
        return false;
      }
      dsu.join(j, perm[j]);
    }
    i = perm[i] + 1;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long _t;
  cin >> _t;
  for (long long _tn = 0; _tn < _t; ++_tn) {
    cin >> n >> k;
    if (k > get2(n)) {
      cout << "-1\n";
      continue;
    }
    for (long long i = 0; i < n;) {
      for (long long x = 1; i + x <= n; ++x) {
        if (mul(get1(x), get2(n - i - x)) >= k) {
          f(x, i, (k - 1) / get2(n - i - x) + 1);
          k = (k - 1) % get2(n - i - x) + 1;
          i += x;
          break;
        } else {
          k -= mul(get1(x), get2(n - i - x));
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
