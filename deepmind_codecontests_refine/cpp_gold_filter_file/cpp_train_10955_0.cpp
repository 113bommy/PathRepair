#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long MOD2 = 998244353;
const long long N = 1000 * 100 + 10;
const long long N2 = 70;
const long double PI = 3.141592653589793;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
std::vector<long long> v[N];
long long isleaf[N];
long long bigflag = 0;
long long root;
std::vector<long long> s;
long long dfs2(long long cur, long long par = -1) {
  vector<long long> g;
  long long flag1 = 0, flag2 = 0;
  for (auto x : v[cur]) {
    if (x != par) {
      if (isleaf[x])
        g.push_back(1);
      else
        g.push_back(dfs2(x, cur) + 1);
    }
  }
  sort(g.begin(), g.end());
  for (auto x : g) {
    if (x % 2 == 1) flag1++;
    if (x % 2 == 0) flag2++;
  }
  if (flag2 && flag1) bigflag++;
  return g[0];
}
void dfs(long long cur, long long level, long long par = -1) {
  long long count = 0;
  long long flag = 0;
  for (auto x : v[cur]) {
    if (x != par) {
      if (isleaf[x]) {
        flag++;
      }
      dfs(x, level + 1, cur);
    }
  }
  if (flag) s.push_back(flag);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  memset(isleaf, 0, sizeof(isleaf));
  long long leaves = 0;
  for (long long i = 0; i < n; ++i) {
    if (v[i].size() == 1) {
      leaves++;
      isleaf[i] = 1;
    } else
      root = i;
  }
  dfs(root, 0, -1);
  long long smth = dfs2(root, -1);
  long long big = n - 1 - leaves + s.size();
  long long small = 1;
  if (bigflag) small = 3;
  cout << small << " " << big << "\n";
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
  return 0;
}
