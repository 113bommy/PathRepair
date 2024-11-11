#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mxn = 303;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) f = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long ksm(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, a[mxn], cnt[mxn][3], s1, s2, res;
vector<int> g[mxn];
void dfs(int u, int pre) {
  if (a[u] == 1)
    cnt[u][1] = 1;
  else if (a[u] == 2)
    cnt[u][2] = 1;
  for (auto v : g[u]) {
    if (v == pre) continue;
    dfs(v, u);
    cnt[u][1] += cnt[v][1];
    cnt[u][2] += cnt[v][2];
  }
  if (cnt[u][1] == s1 && cnt[u][2] == 0)
    res++;
  else if (cnt[u][2] == s2 && cnt[u][1] == 0)
    res++;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  cin >> n;
  s1 = 0, s2 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 1)
      s1++;
    else if (a[i] == 2)
      s2++;
  }
  int u, v;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  res = 0;
  dfs(1, 0);
  cout << res << endl;
  return 0;
}
