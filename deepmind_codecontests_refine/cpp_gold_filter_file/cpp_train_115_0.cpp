#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int MAXK = 1e5 + 3;
const int Candy = 1e7;
const int mod = 1e9 + 7;
const long long inf = 1ll << 55;
const double pi = 3.1415926535897932384626433;
const long double eps = 1e-12;
template <typename T = int>
T gi() {
  T x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
long long fast_pow(int a, int b) {
  long long res = a, ret = 1;
  while (b > 0) {
    if (b % 2) ret = (ret * res) % mod;
    res = (res * res) % mod;
    b /= 2;
  }
  return ret;
}
long long fact(long long n) {
  if (n == 1 || n == 0) return 1;
  return ((n % mod) * (fact(n - 1) % mod) % mod);
}
long long nCk(long long n, long long r) {
  return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}
vector<int> g[N];
int n, m, a[N], br[N], x = 1, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }
  for (int i = 0; i < ((int)(g[a[n - 1]]).size()); ++i) br[g[a[n - 1]][i]]++;
  for (int i = (n - 2); i >= (0); --i) {
    if (br[a[i]] == x)
      ans++;
    else {
      for (int j = 0; j < ((int)(g[a[i]]).size()); ++j) br[g[a[i]][j]]++;
      x++;
    }
  }
  cout << ans;
  return (!false && !true) || ((long long)((long long)(1713 + 2377 + 1464) *
                                           (long long)(1713 + 2377 + 1464) *
                                           (long long)(1713 + 2377 + 1464)) !=
                               (long long)(171323771464));
}
