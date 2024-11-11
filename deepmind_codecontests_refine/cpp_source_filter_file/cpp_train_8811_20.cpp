#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{ ";
  for (const T& t : v) os << t << ", ";
  return os << "}";
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& pp) {
  return os << "{ " << pp.first << ", " << pp.second << " }";
}
struct SegmentTree {
  vector<long long> st;
  long long n;
  SegmentTree(long long n_, vector<long long>& a) : st(4 * n_), n(n_) {
    build(a, 0, 0, n - 1);
  }
  void build(vector<long long>& a, long long p, long long L, long long R) {
    if (L == R)
      st[p] = a[L];
    else {
      build(a, 2 * p + 1, L, (L + R) / 2);
      build(a, 2 * p + 2, (L + R) / 2 + 1, R);
      st[p] = min(st[2 * p + 1], st[2 * p + 2]);
    }
  }
  long long query(long long p, long long L, long long R, long long i,
                  long long j) {
    if (R < i || j < L) return 1e9;
    if (i <= L && R <= j) return st[p];
    return min(query(2 * p + 1, L, (L + R) / 2, i, j),
               query(2 * p + 2, (L + R) / 2 + 1, R, i, j));
  }
};
signed main() {
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> lrs(k + 2);
  for (long long i = 0; i < k; ++i)
    cin >> lrs[i + 1].first >> lrs[i + 1].second;
  ++k;
  lrs[0] = {0, 0};
  lrs[k] = {2 * n, 2 * n};
  vector<vector<long long>> dp(2, vector<long long>(n + 1, 1e9));
  dp[0][n] = dp[1][n] = 0;
  while (k--) {
    SegmentTree st[2] = {SegmentTree(n + 1, dp[0]), SegmentTree(n + 1, dp[1])};
    long long l = lrs[k].first, r = lrs[k].second;
    long long dl = lrs[k + 1].first - l, dr = lrs[k + 1].second - r;
    vector<vector<long long>> nextdp(2, vector<long long>(n + 1, 1e9));
    for (long long i = 0; i < 2; ++i) {
      for (long long j = 0; j <= n; ++j) {
        long long& a = nextdp[i][j];
        ;
        ;
        long long newj = j + (i == 0 ? dl : 0);
        ;
        ;
        if (newj <= n) a = dp[i][newj];
        ;
        long long minj, maxj;
        if (i == 0) {
          minj = j + dl - (r - l);
          maxj = j + dl;
        } else {
          minj = j;
          maxj = j + (r - l);
        }
        maxj = min(maxj, n);
        if (minj <= n) {
          a = min(a, st[i].query(0, 0, n, newj, maxj) + 2);
        };
        if (i == 0) {
          if (j <= n) {
            a = min(a, st[1].query(0, 0, n, j, min(j + r - l, n)) + 1);
          };
          ;
          ;
        } else {
          if (j + dr <= n) {
            a = min(a, st[0].query(0, 0, n, j + dr, min(j + dl, n)) + 1);
          };
          ;
        }
      }
    }
    dp = nextdp;
  }
  if (dp[0][0] == 1e9) {
    cout << "Hungry" << endl;
  } else {
    cout << "Full\n" << dp[0][0] << endl;
  }
  return 0;
}
