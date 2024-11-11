#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int mod = 1e9 + 7;
const int base = 300;
pair<int, int> p[N];
int m, n, t, k, a[N], ans, b[N], tong, dp[N], d[N], c[N], lab[N], cnt, l[N],
    r[N], L, R, mn;
vector<int> val, adj[N], kq;
unordered_set<int> gr[N], pr[N];
string s;
int pw(int k, int n) {
  int total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = total * k % mod;
    k = k * k % mod;
  }
  return total;
}
int findp(int u) { return lab[u] < 0 ? u : lab[u] = findp(lab[u]); }
void hop(int u, int v) {
  if (lab[u] > lab[v]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
}
void dfs(int u, int p) {
  ++a[b[u]];
  for (int v : adj[u]) {
    if (v == p) continue;
    b[v] = b[u] == 1 ? 0 : 1;
    dfs(v, u);
  }
}
void ask(int x) {
  cout << x << endl;
  cin >> k;
  a[k] += x;
}
void init() {
  for (int i = 0; i < n; i++) {
    if (i) a[i] = a[i - 1];
    if (s[i] == '(')
      ++a[i];
    else
      --a[i];
    if (a[i] < a[mn]) mn = i;
  }
  if (!a[n - 1]) {
    ++mn;
    rotate(s.begin(), s.begin() + mn, s.end());
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        kq.push_back(i);
      } else {
        l[i] = kq.back();
        r[kq.back()] = i;
        kq.pop_back();
      }
    }
  }
}
void cal(int x, int y, int dep) {
  if (x + 1 == y) return;
  for (int i = y - 1; i > x; i = l[i] - 1) {
    cal(l[i], i, dep + 1);
    ++d[y];
    if (!dep && d[i] + 1 > ans) {
      ans = d[i] + 1;
      L = l[i];
      R = i;
    }
  }
}
void sol() {
  cin >> n >> s;
  init();
  if (a[n - 1]) {
    cout << 0 << '\n' << 1 << " " << 1;
    return;
  }
  for (int i = 0; i < n; i = r[i] + 1) {
    cal(i, r[i], 0);
    ++tong;
  }
  for (int i = 0; i < n; i = r[i] + 1) {
    if (d[r[i]] - tong + 1 > ans) {
      ans = d[r[i]] - tong + 1;
      L = i;
      R = r[i];
    }
  }
  L = (L + mn) % n + 1;
  R = (R + mn) % n + 1;
  cout << ans + tong << '\n' << L << " " << R;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  if (fopen("tests"
            ".in",
            "r")) {
    freopen(
        "tests"
        ".in",
        "r", stdin);
  }
  int ntest = 1;
  while (ntest-- > 0) sol();
}
