#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
const double PI = acos(-1.0);
const double angcst = PI / 180.0;
const long long mod = 998244353;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long qmul(long long a, long long b) {
  long long r = 0;
  while (b) {
    if (b & 1) r = (r + a) % mod;
    b >>= 1;
    a = (a + a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % mod;
    n >>= 1;
    a = (a * a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n, long long p) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % p;
    n >>= 1;
    a = (a * a) % p;
  }
  return r;
}
vector<int> G[100050];
vector<pair<int, int> > ans;
int maxdeg;
void dfs(int p, int fa, int tim) {
  ans.push_back(pair<int, int>(p, tim));
  int curtim = tim;
  int tmp = G[p].size();
  for (int it : G[p]) {
    if (it == fa) continue;
    if (curtim == maxdeg) {
      curtim = maxdeg - tmp;
      ans.push_back(pair<int, int>(p, curtim));
    }
    curtim++;
    tmp--;
    dfs(it, p, curtim);
  }
  if (p != 1) {
    if (curtim + 1 != tim) ans.push_back(pair<int, int>(p, tim - 1));
    ans.push_back(pair<int, int>(fa, tim));
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = (1); i < (n); i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = (1); i <= (n); i++) maxdeg = max(maxdeg, (int)G[i].size());
  dfs(1, 0, 0);
  cout << ans.size() << '\n';
  for (pair<int, int> pd : ans) cout << pd.first << ' ' << pd.second << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
