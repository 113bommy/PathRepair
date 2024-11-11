#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long qpow(long long n, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ret;
}
vector<int> e[N];
int ans[N];
int succ;
int dfs(int k, int u, int fa) {
  int cnt = 0;
  for (int v : e[u])
    if (v != fa) {
      cnt += dfs(k, v, u);
    }
  if (cnt % k == 0) return 1;
  if (cnt % k == k - 1) return 0;
  succ = 0;
  return 0;
}
void main0() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
      ans[i] = (i == 1 ? qpow(2, n - 1) : 0);
    }
    for (int i = 1; i <= n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    for (int i = 2; i <= n - 1; ++i)
      if ((n - 1) % i == 0) {
        succ = 1;
        dfs(i, 1, -1);
        if (succ) ans[1]--, ans[i]++;
      }
    for (int i = 2; i <= n; ++i) {
      for (int j = 2; i * j <= n; ++j) {
        ans[i] -= ans[i * j];
        ans[1] += ans[i * j];
      }
    }
    ans[1] += mod;
    ans[1] %= mod;
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
}
