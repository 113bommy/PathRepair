#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
mt19937 gen;
const long long SQRT = 700;
const long long MAXN = 3e5 + 10;
const long long MAXC = 100;
long long n, q;
vector<long long> a, l, r, k;
vector<long long> ind, ans;
long long cnt[MAXN];
bool comp(long long a, long long b) {
  if (l[a] / SQRT != l[b] / SQRT) {
    return l[a] < l[b];
  }
  return r[a] < r[b];
}
inline void add(long long i) { ++cnt[a[i]]; }
inline void del(long long i) { --cnt[a[i]]; }
void mo() {
  ind.resize(q);
  ans.resize(q, inf);
  iota((ind).begin(), (ind).end(), 0);
  sort((ind).begin(), (ind).end(), comp);
  long long cl = 0, cr = -1;
  for (long long i : ind) {
    long long l = ::l[i], r = ::r[i], k = ::k[i];
    while (cl > l) {
      add(cl - 1);
      --cl;
    }
    while (cr < r) {
      add(cr + 1);
      ++cr;
    }
    while (cl < l) {
      del(cl);
      ++cl;
    }
    while (cr > r) {
      del(cr);
      --cr;
    }
    long long cur = inf;
    for (long long i = 0; i < MAXC; i++) {
      long long j = l + rand() % (r - l + 1);
      if (cnt[a[j]] > (r - l + 1) / k) {
        (cur) = ((cur) > (a[j])) ? (a[j]) : (cur);
      }
    }
    ans[i] = cur;
  }
}
inline void solve() {
  mo();
  for (long long i = 0; i < q; i++) {
    if (ans[i] == inf) {
      cout << -1 << "\n";
    } else {
      cout << ans[i] << "\n";
    }
  }
}
inline void read() {
  cin >> n >> q;
  a.resize(n), l.resize(q), r.resize(q), k.resize(q);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < q; i++) {
    cin >> l[i] >> r[i] >> k[i];
    --l[i], --r[i];
  }
}
