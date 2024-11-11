#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 1010101;
int n, c, L;
int l[N], r[N], ls[N], rs[N], mil[N], mir[N];
void dfs(int u, int low) {
  if (l[u]) {
    ls[u] = ++L;
    dfs(L, l[u]);
    l[u] = 0;
    if (L >= mir[u]) {
      cout << "IMPOSSIBLE"
           << "\n";
      exit(0);
    }
  }
  if (r[u]) {
    rs[u] = ++L;
    dfs(L, r[u]);
    r[u] = 0;
  }
  if (L >= low) return;
  if (!rs[u]) rs[u] = ++L;
  dfs(rs[u], low);
}
bool solve() {
  fill_n(mil + 1, n, n + 1);
  fill_n(mir + 1, n, n + 1);
  for (int i = (0); i < (c); i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    if (u > v) return 0;
    if (s[0] == 'L') {
      l[u] = max(l[u], v);
      mil[u] = min(mil[u], v);
    } else {
      r[u] = max(r[u], v);
      mir[u] = min(mir[u], v);
    }
  }
  for (int u = (1); u < (n + 1); u++)
    if (l[u] && r[u] && l[u] > mir[u]) return 0;
  L = 1;
  dfs(1, n);
  return 1;
}
void print(int u) {
  if (!u) return;
  print(ls[u]);
  cout << u << " ";
  print(rs[u]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> c;
  if (solve()) {
    print(1);
  } else {
    cout << "IMPOSSIBLE"
         << "\n";
  }
  return 0;
}
