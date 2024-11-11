#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const long long mod = 1000000007;
vector<long long> g[N];
long long bit[N][2];
long long l[N], r[N];
long long deep[N];
long long cont;
void init() {
  cont = 1;
  memset(deep, 0, sizeof(deep));
  memset(bit, 0, sizeof(bit));
}
void dfs(long long u, long long dep) {
  l[u] = cont++;
  deep[u] = dep;
  long long n = g[u].size();
  for (long long i = 0; i < n; i++) {
    long long v = g[u][i];
    dfs(v, dep + 1);
  }
  r[u] = cont - 1;
}
long long lowbit(long long x) { return x & (-x); }
void update(long long x, long long index, long long val) {
  while (x < N) {
    bit[x][index] = (bit[x][index] + val) % mod;
    x += lowbit(x);
  }
}
long long get_sum(long long x, long long index) {
  long long res = 0;
  while (x > 0) {
    res = (res + bit[x][index]) % mod;
    x -= lowbit(x);
  }
  return res;
}
int main() {
  long long n, q;
  long long x;
  long long op, v;
  long long k;
  init();
  cin >> n;
  for (long long i = 2; i <= n; i++) {
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1, 1);
  memset(bit, 0, sizeof(bit));
  cin >> q;
  while (q--) {
    cin >> op >> v;
    if (op == 1) {
      cin >> x >> k;
      long long L = l[v];
      long long R = r[v];
      long long val = x + k * deep[v];
      update(L, 0, val);
      update(R + 1, 0, -val);
      update(L, 1, k);
      update(R + 1, 1, k);
    } else {
      long long id = l[v];
      long long s1 = get_sum(id, 0);
      long long s2 = get_sum(id, 1);
      long long ans = s1 - s2 * deep[v];
      ans = (ans % mod + mod) % mod;
      cout << ans << endl;
    }
  }
  return 0;
}
