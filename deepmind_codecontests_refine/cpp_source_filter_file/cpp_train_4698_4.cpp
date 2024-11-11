#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e5 + 5, mod = 1e9 + 7, inf = mod;
long long n;
set<long long> s[3];
long long q;
struct {
  vector<long long> sum = vector<long long>(maxn, 0);
  void add(long long i, long long v) {
    for (; i < maxn; i += i & -i) {
      sum[i] += v;
    }
  }
  long long get(long long i) {
    long long r = 0;
    for (; i > 0; i -= i & -i) {
      r += sum[i];
    }
    return r;
  }
  long long getran(long long l, long long r) { return get(r) - get(l - 1); }
} bit[3];
long long arr[maxn];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  map<long long, long long> m;
  m['R'] = 0;
  m['P'] = 1, m['S'] = 2;
  for (long long i = (long long)1; i <= (long long)n; i++) {
    char c;
    cin >> c;
    arr[i] = m[c];
    s[arr[i]].insert(i);
    bit[arr[i]].add(i, 1);
  }
  for (long long i = (long long)0; i <= (long long)q; i++) {
    if (i) {
      char c;
      long long p;
      cin >> p >> c;
      s[arr[p]].erase(p);
      bit[arr[p]].add(p, -1);
      arr[p] = m[c];
      s[arr[p]].insert(p);
      bit[arr[p]].add(p, 1);
    }
    long long ans = 0;
    for (long long t = (long long)0; t <= (long long)2; t++) {
      long long nxt = (t + 1) % 3, prv = (t + 2) % 3;
      if (s[nxt].empty())
        ans += s[t].size();
      else {
        long long l1 = (s[prv].empty() ? 1 : *s[prv].rbegin() + 1);
        long long r1 = *s[nxt].rbegin();
        long long r2 = (s[prv].empty() ? n : *s[prv].begin() - 1);
        long long l2 = *s[nxt].begin();
        if (l1 > r1) l1 = r1 = 0;
        if (l2 > r2) l2 = r2 = 0;
        if (max(l1, l2) <= min(r1, r2)) {
          l1 = min(l1, l2);
          r1 = max(r1, r2);
          l1 = r1 = 0;
        }
        ans +=
            bit[t].getran(1, n) - bit[t].getran(l1, r1) - bit[t].getran(l2, r2);
      }
    }
    cout << ans << '\n';
  }
}
