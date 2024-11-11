#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e18;
const long long mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powm(long long a, long long b, long long m);
long long lvr[100001];
pair<long long, long long> a[1200001];
long long lazy[1200001];
inline void pushdown(long long seg, long long lb, long long rb) {
  if (lb == rb) {
    a[seg].second = lb;
    return;
  }
  if (lazy[seg]) {
    a[seg * 2].first += lazy[seg];
    a[seg * 2 + 1].first += lazy[seg];
    lazy[seg * 2] += lazy[seg];
    lazy[seg * 2 + 1] += lazy[seg];
    lazy[seg] = 0;
  }
}
void update(long long seg, long long lb, long long rb, long long l, long long r,
            long long val) {
  if (l > rb || r < lb) return;
  if (l <= lb && rb <= r) {
    a[seg].first += val;
    lazy[seg] += val;
    return;
  }
  pushdown(seg, lb, rb);
  update(seg * 2, lb, (lb + rb) / 2, l, r, val);
  update(seg * 2 + 1, (lb + rb) / 2 + 1, rb, l, r, val);
  a[seg] = max(a[seg * 2], a[seg * 2 + 1]);
}
bool active[100001];
bool answ[100001];
long long tola[100001][3];
void solve() {
  long long n;
  cin >> n;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> add, rem;
  long long l, v, r;
  for (long long i = 1; i <= n; i++) {
    cin >> l >> v >> r;
    tola[i][0] = l;
    tola[i][1] = v;
    tola[i][2] = r;
    add.push_back({{v, i}, {l, v}});
    rem.push_back({{r, i}, {l, v}});
  }
  sort(add.begin(), add.end());
  sort(rem.begin(), rem.end());
  long long ans = 0;
  add.push_back({{inf, inf}, {inf, inf}});
  rem.push_back({{inf, inf}, {inf, inf}});
  for (long long i = 0, j = 0; i <= n && j < n;) {
    if (add[i].first.first <= rem[j].first.first) {
      update(1, 1, 300000, add[i].second.first, add[i].second.second, 1);
      ans = max(ans, a[1].first);
      i++;
    } else {
      update(1, 1, 300000, rem[j].second.first, rem[j].second.second, -1);
      j++;
    }
  }
  cout << ans << endl;
  for (long long i = 0, j = 0; i < n;) {
    if (add[i].first.first <= rem[j].first.first) {
      update(1, 1, 300000, add[i].second.first, add[i].second.second, 1);
      active[add[i].first.second] = 1;
      if (ans == a[1].first) {
        long long teans = 0;
        vector<pair<long long, long long>> ls, rs;
        for (long long i = 1; i <= n; i++)
          if (active[i]) {
            ls.push_back({tola[i][0], i});
            rs.push_back({tola[i][1], i});
          }
        sort(ls.begin(), ls.end());
        sort(rs.begin(), rs.end());
        for (long long i = 0, j = 0; i < ls.size();) {
          if (ls[i].first <= rs[j].first) {
            answ[ls[i].second] = 1;
            teans++;
            i++;
          } else {
            answ[rs[j].second] = 0;
            teans--;
            j++;
          }
          if (teans == ans) {
            for (long long k = 1; k <= n; k++)
              if (answ[k]) cout << k << " ";
            return;
          }
        }
        return;
      }
      i++;
    } else {
      update(1, 1, 300000, rem[j].second.first, rem[j].second.second, -1);
      active[add[j].first.second] = 0;
      j++;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::steady_clock::now().time_since_epoch().count());
  cout << fixed << setprecision(10);
  long long t = 1;
  auto clk = clock();
  while (t--) solve();
  return 0;
}
long long powm(long long a, long long b, long long m) {
  long long te = 1;
  while (b) {
    if (b & 1) te = (te * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return te;
}
