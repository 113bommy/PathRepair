#include <bits/stdc++.h>
using namespace std;
long long power(long long p, long long j) {
  long long res = 1;
  p = p % 998244353;
  while (j > 0) {
    if (j & 1) res = (res * p) % 998244353;
    j = j >> 1;
    p = (p * p) % 998244353;
  }
  return res;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long dice(long long d, long long p) {
  uniform_int_distribution<long long> uid(d, p);
  return uid(rng);
}
using cd = complex<long double>;
const long double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  long long n = a.size();
  for (long long i = 1, j = 0; i < n; i++) {
    long long bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (long long len = 2; len <= n; len <<= 1) {
    long double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (long long i = 0; i < n; i += len) {
      cd w(1);
      for (long long j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  long long n = a.size(), m = b.size();
  long long z[n + m];
  memset(z, 0, sizeof(z));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      z[i + j] += a[i] * b[j];
      z[i + j] %= 998244353;
    }
  }
  vector<long long> result;
  for (long long i = 0; i < min(n + m - 1, 1501LL); i++) result.push_back(z[i]);
  return result;
}
long long n;
long long a[1513][1513];
vector<long long> dp[1513];
long long p[1513];
vector<long long> d[1513];
long long c[1513];
void merge(long long x, long long y) {
  if (d[x].size() < d[y].size()) swap(x, y);
  for (long long i = 0; i < d[x].size(); i++)
    for (long long j = 0; j < d[y].size(); j++)
      c[x] = max(c[x], a[d[x][i]][d[y][j]]);
  for (long long i = 0; i < d[y].size(); i++) {
    p[d[y][i]] = x;
    d[x].push_back(d[y][i]);
  }
  dp[x] = multiply(dp[x], dp[y]);
  if (dp[x].size() > 1513) dp[x].resize(1513);
  for (long long i = 0; i < dp[x].size(); i++) dp[x][i] %= 998244353;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) cin >> a[i][j];
  for (long long i = 1; i <= n; i++) {
    p[i] = i;
    d[i].push_back(i);
    dp[i].push_back(0);
    dp[i].push_back(1);
  }
  vector<pair<long long, pair<long long, long long>>> k;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j < i; j++)
      k.push_back(make_pair(a[i][j], make_pair(i, j)));
  sort(k.begin(), k.end());
  for (auto h : k) {
    long long t = h.first;
    long long a = h.second.first;
    long long b = h.second.second;
    a = p[a];
    b = p[b];
    if (a != b) merge(a, b);
    if (c[a] == t) dp[a][1] = (dp[a][1] + 1) % 998244353;
  }
  vector<long long> h = dp[p[1]];
  for (long long i = 1; i <= n; i++) cout << max(h[i], 0LL) << " ";
  return 0;
}
