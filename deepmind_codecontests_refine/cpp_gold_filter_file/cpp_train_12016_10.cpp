#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
void fun() {}
const long long N = 100000 + 5;
vector<long long> v[N];
long long pr[N][18];
long long in[N], tim[N];
long long depth[N];
long long timer;
void dfs(long long x, long long par) {
  pr[x][0] = par;
  in[x] = timer++;
  tim[timer - 1] = x;
  for (long long i = 1; i <= 17; i++) pr[x][i] = pr[pr[x][i - 1]][i - 1];
  for (auto it : v[x]) {
    if (it == par) continue;
    depth[it] = depth[x] + 1;
    dfs(it, x);
  }
}
long long find_lca(long long x, long long y) {
  if (x == y) return x;
  if (depth[y] < depth[x]) swap(x, y);
  for (long long i = 17; i >= 0; i--) {
    if (depth[pr[y][i]] >= depth[x]) {
      y = pr[y][i];
    }
  }
  if (x == y) return x;
  for (long long i = 17; i >= 0; i--) {
    if (pr[x][i] != pr[y][i]) {
      x = pr[x][i];
      y = pr[y][i];
    }
  }
  return pr[x][0];
}
long long dis(long long x, long long y) {
  return (depth[x] + depth[y] - (depth[find_lca(x, y)] << 1ll));
}
signed main() {
  fun();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  k--;
  long long mx = 0;
  set<long long> s;
  for (long long i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  depth[1] = 1;
  dfs(1, 0);
  long long cnt1 = 1, cnt2 = 1;
  long long ans = 0;
  while (cnt2 <= n) {
    if (s.empty()) {
      s.insert(in[cnt2]);
      cnt2++;
      continue;
    }
    auto it = s.upper_bound(in[cnt2]);
    long long a, b;
    if (it == s.end() || it == s.begin()) {
      a = tim[*s.begin()];
      b = tim[*(--s.end())];
    } else {
      a = tim[*it];
      b = tim[*(--it)];
    }
    long long temp = (dis(cnt2, a) + dis(cnt2, b) - dis(a, b)) / 2;
    if (ans + temp <= k) {
      mx = max(mx, cnt2 - cnt1);
      s.insert(in[cnt2]);
      cnt2++;
      ans += temp;
    } else {
      ans += temp;
      s.insert(in[cnt2]);
      while (ans > k) {
        s.erase(in[cnt1]);
        auto it = s.upper_bound(in[cnt1]);
        long long a, b;
        if (it == s.end() || it == s.begin()) {
          a = tim[*s.begin()];
          b = tim[*(--s.end())];
        } else {
          a = tim[*it];
          b = tim[*(--it)];
        }
        long long temp1 = (dis(cnt1, a) + dis(cnt1, b) - dis(a, b)) / 2;
        ans -= temp1;
        mx = max(mx, cnt2 - 1 - cnt1);
        cnt1++;
      }
      cnt2++;
    }
  }
  cout << mx + 1 << "\n";
}
