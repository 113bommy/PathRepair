#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937_64 rnd(time(0));
long long MOD = 998244353;
const long double E = 1e-10;
long long n, m, k, T, ans[500005];
vector<long long> c[500005];
long long binpow(long long h, long long r, long long md) {
  long long l = 1;
  while (r) {
    if (r & 1) l = (l * h) % md;
    h = (h * h) % md;
    r /= 2;
  }
  return l;
}
long long read() {
  char c = getchar();
  while (!isdigit(c)) {
    c = getchar();
  }
  long long res = 0;
  while (isdigit(c)) {
    res = res * 10 + c - '0';
    c = getchar();
  }
  return res;
}
long long gcd(long long x, long long y) {
  while (x && y) {
    if (x < y) swap(x, y);
    x %= y;
  }
  return x + y;
}
pair<long long, long long> dfs(int h, int p = -1) {
  long long z = 0;
  for (int i = 0; i < c[h].size(); i++)
    if (c[h][i] != p) {
      pair<long long, long long> u = dfs(c[h][i], h);
      if (!u.first) return make_pair(0, 0);
      z += u.second;
    }
  if (z % T == 0)
    return make_pair(1, 1);
  else if ((z + 1) % T == 0)
    return make_pair(1, 0);
  else
    return make_pair(0, 0);
}
void solve() {
  cin >> n;
  long long x = n - 1, p = sqrt(x);
  vector<long long> v;
  for (int i = 1; i <= n; i++) ans[i] = 0, c[i].clear();
  for (int i = 1; i <= p; i++)
    if (x % i == 0) {
      v.push_back(i);
      if (x / i != i) v.push_back(x / i);
    }
  for (int i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    c[x].push_back(y);
    c[y].push_back(x);
  }
  ans[1] = binpow(2, n - 1, MOD);
  for (int i = 1; i < v.size(); i++) {
    T = v[i];
    pair<long long, long long> o = dfs(1);
    if (o.first && o.second) ans[v[i]] = 1;
  }
  for (int i = n; i > 0; i--) {
    for (int j = i * 2; j <= n; j += i) ans[i] -= ans[j];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
