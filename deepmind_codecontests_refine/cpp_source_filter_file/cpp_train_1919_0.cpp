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
const long long N = 300001 + 100;
long long in[N], out[N];
vector<long long> v[N];
long long timer;
long long hks[4 * N];
long long sk[4 * N];
long long h[N];
void dfs(long long x) {
  in[x] = ++timer;
  for (auto it : v[x]) {
    h[it] = h[x] + 1;
    dfs(it);
  }
  out[x] = timer;
}
void update(long long v, long long x, long long k, long long l, long long r,
            long long node) {
  if (in[v] > r || out[v] < l) return;
  if (in[v] <= l && out[v] >= r) {
    hks[node] = (hks[node] + x) % mod;
    long long a = (k * h[v]) % mod;
    hks[node] = (hks[node] + a) % mod;
    sk[node] = (sk[node] + k) % mod;
    return;
  }
  long long mid = (l + r) / 2;
  update(v, x, k, l, mid, node * 2);
  update(v, x, k, mid + 1, r, node * 2 + 1);
}
long long query(long long v, long long node, long long l, long long r) {
  long long ans = (hks[node] + mod - ((sk[node] * h[v]) % mod)) % mod;
  if (in[v] <= l && r <= out[v]) return ans;
  long long mid = (l + r) / 2;
  if (in[v] <= mid)
    ans = (ans + query(v, node * 2, l, mid) % mod) % mod;
  else
    (ans + query(v, node * 2 + 1, mid + 1, r) % mod) % mod;
  return ans;
}
signed main() {
  fun();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long x, k;
  for (long long i = 2; i <= n; i++) {
    cin >> x;
    v[x].push_back(i);
  }
  h[1] = 1;
  dfs(1);
  long long t;
  cin >> t;
  while (t--) {
    long long num;
    cin >> num;
    long long m;
    if (num == 1) {
      cin >> m >> x >> k;
      update(m, x, k, 1, out[1], 1);
    } else {
      cin >> m;
      cout << query(m, 1, 1, out[1]) << "\n";
    }
  }
}
