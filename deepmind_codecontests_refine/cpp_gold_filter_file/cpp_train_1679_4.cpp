#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
struct edge {
  long long u, v, w;
  edge(long long a, long long b, long long c) {
    u = a;
    v = b;
    w = c;
  }
};
struct compare {
  bool operator()(const edge a, const edge b) const {
    if (a.u == b.u) {
      if (a.v == b.v) {
        return a.w < b.w;
      }
      return a.v < b.v;
    }
    return a.u < b.u;
  }
};
const long long nax = 5e5 + 5;
long long table[nax][20], arr[nax], n;
vector<long long> g[nax];
long long root = 1;
long long ans = 0;
void dfs(long long x, long long p) {
  table[x][0] = p;
  for (long long i = 1; i < 20; i++) {
    if (table[x][i - 1] == -1) {
      continue;
    }
    table[x][i] = table[table[x][i - 1]][i - 1];
  }
  long long mx = 1LL << 60;
  long long d = 0;
  for (d = 0; d < 20 && table[x][d] != -1; d++) {
    mx = min(mx, (d + 1) * arr[table[x][d]] + arr[x]);
  }
  mx = min(mx, (d + 1) * arr[root] + arr[x]);
  if (p != -1) {
    ans += mx;
  }
  for (long long i : g[x]) {
    if (i == p) {
      ;
    } else {
      dfs(i, x);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] < arr[root]) {
      root = i;
    }
  }
  for (long long i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(table, -1, sizeof(table));
  dfs(root, -1);
  cout << ans << "\n";
}
