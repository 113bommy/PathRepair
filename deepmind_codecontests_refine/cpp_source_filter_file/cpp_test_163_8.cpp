#include <bits/stdc++.h>
using namespace std;
const long long MX = 400005;
const long long MOD = 1e9 + 7;
long long t, n, m, a, b, c, d, p;
vector<long long> adj[MX];
long long dx[2] = {1, -1};
long long dy[2] = {1, -1};
bool cyc[MX];
bool vis[MX];
long long ans, pr, cnt, ip;
bool done;
stack<long long> st;
long long mult(long long a, long long b) {
  if (b < 0) b += MOD;
  return ((long long)a * b) % MOD;
}
long long mult(vector<long long> a) {
  long long ret = 1;
  for (long long k : a) ret = mult(ret, k);
  return ret;
}
long long add(long long a, long long b) { return (a + b) % MOD; }
long long bpow(long long a, long long b) {
  if (b == 0) return 1;
  long long x = bpow(a, b / 2);
  x = mult(x, x);
  if (b & 1) x = mult(x, a);
  return x;
}
long long inv(long long x) {
  if (x < 0) x += MOD;
  return bpow(x, MOD - 2);
}
void dfs(long long x) {
  vis[x] = 1;
  st.push(x);
  for (long long k : adj[x]) {
    if (vis[k]) {
      st.push(k);
      done = 1;
      return;
    }
    dfs(k);
    if (done) return;
  }
  st.pop();
}
void dfs2(long long u, long long q, long long dist) {
  vis[u] = 1;
  long long x = u / 4 / m, y = (u / 4) % m;
  if (x == c || y == d) {
    if (!cyc[u])
      ans = add(ans, mult(q, dist));
    else
      ans = add(ans, mult({p, q, dist, ip}) + mult({p, q, cnt, pr, ip, ip}));
  }
  for (long long k : adj[u]) {
    if (!vis[k]) dfs2(k, mult(q, (x == c || y == d ? (1 - p) : 1)), dist + 1);
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b >> c >> d >> p;
    a--;
    b--;
    c--;
    d--;
    p = mult(p, inv(100));
    long long N = n * m * 4;
    ans = 0;
    done = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        for (long long x = 0; x <= 1; x++) {
          for (long long y = 0; y <= 1; y++) {
            long long u = 4 * (m * i + j) + 2 * x + y;
            adj[u].clear();
            long long xx = (i + dx[x] < 0 || i + dx[x] == n) ? !x : x;
            long long yy = (j + dy[y] < 0 || j + dy[y] == m) ? !y : y;
            adj[u].push_back(4 * (m * (i + dx[xx]) + j + dy[yy]) + 2 * xx + yy);
            vis[u] = cyc[u] = 0;
          }
        }
      }
    }
    dfs(4 * (m * a + b));
    cnt = 0;
    vector<bool> proc(N);
    long long u;
    pr = 1;
    while (!proc[(u = st.top())]) {
      proc[u] = 1;
      cnt++;
      cyc[u] = 1;
      long long x = u / 4 / m, y = (u / 4) % m;
      if (x == c || y == d) {
        pr = mult(pr, 1 - p);
      }
      st.pop();
    }
    ip = inv(1 - pr);
    while (!st.empty()) st.pop();
    for (long long i = 0; i < 2 * N; i++) vis[i] = 0;
    dfs2(4 * (m * a + b), 1, 0);
    cout << ans << "\n";
  }
}
