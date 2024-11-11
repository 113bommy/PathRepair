#include <bits/stdc++.h>
using namespace std;
vector<long long int> p[200005], q[200005], f(400005, 0), b(400005, 0),
    a(200005), d(400005), e(400005);
map<pair<long long int, long long int>, long long int> mp;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res % 998244353;
}
void fact(long long int i) {
  f[0] = 1;
  for (long long int k = 1; k <= i; k++) {
    (f[k] = f[k - 1] * k) %= 998244353;
  }
}
long long int isprime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int find(long long int x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
bool cmp(long long int x, long long int y) { return x < y; }
long long int comb(long long int i, long long int j) {
  long long int k = f[i];
  long long int g = (f[j] * (f[i - j])) % 998244353;
  long long int h = bpow(g, 998244353 - 2);
  return (k * h) % 998244353;
}
long long int t = 0, n, m;
void dfs(long long int i, long long int pr) {
  t++;
  d[i] = t;
  for (auto u : p[i]) {
    if (u != pr) {
      b[u] = -b[i];
      dfs(u, i);
    }
  }
  t++;
  e[i] = t;
}
void add(long long int i, long long int val) {
  while (i <= 2 * n) {
    f[i] += val;
    i += i & -i;
  }
}
long long int cal(long long int i) {
  long long int s = 0;
  while (i > 0) {
    s += f[i];
    i -= i & -i;
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long int u, v;
  for (long long int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    p[u].push_back(v);
    p[v].push_back(u);
  }
  b[1] = 1;
  dfs(1, 0);
  while (m--) {
    long long int x, y, z;
    cin >> x;
    if (x == 1) {
      cin >> y >> z;
      add(d[y], b[y] * z);
      add(e[y], -b[y] * z);
    }
    if (x == 2) {
      cin >> y;
      long long int s = a[y] + b[y] * cal(y);
      cout << s << "\n";
    }
  }
}
