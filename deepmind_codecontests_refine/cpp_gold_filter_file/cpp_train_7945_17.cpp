#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 5;
const long long naxN = 2e2 + 5;
long long fact[naxN], inv_fact[naxN];
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2)
      res = (res * a) % 1000000007, n--;
    else
      a = (a * a) % 1000000007, n /= 2;
  }
  return res % 1000000007;
}
void init() {
  fact[0] = inv_fact[0] = 1;
  for (long long i = 1; i < naxN; i++) {
    fact[i] = (i * fact[i - 1]) % 1000000007;
    inv_fact[i] = power(fact[i], 1000000007 - 2) % 1000000007;
  }
}
long long ncr(long long a, long long b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return (fact[a] % 1000000007 * inv_fact[b] % 1000000007 * inv_fact[a - b] %
          1000000007) %
         1000000007;
}
long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long par[30];
long long R[30];
long long find(long long a) {
  if (par[a] < 0) return a;
  return par[a] = find(par[a]);
}
void merge(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (R[a] >= R[b]) {
    par[b] = a;
    R[a] += R[b];
  } else {
    par[a] = b;
    R[b] += R[a];
  }
}
const long long maxN = 1e5 + 5;
void solve() {
  long long n;
  cin >> n;
  map<long long, vector<pair<long long, long long>>> sx, sy;
  vector<pair<long long, long long>> points;
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    points.push_back({a, b});
    sx[a].push_back({a, b});
    sy[b].push_back({a, b});
  }
  long long cnt = 0;
  for (long long i = 0; i < (long long)points.size(); i++) {
    long long u = 0, d = 0, r = 0, l = 0;
    long long a = points[i].first, b = points[i].second;
    for (long long j = 0; j < (long long)sx[a].size(); j++) {
      long long y = sx[a][j].second;
      if (y > b) u = 1;
      if (y < b) d = 1;
    }
    for (long long j = 0; j < (long long)sy[b].size(); j++) {
      long long x = sy[b][j].first;
      if (x > a) r = 1;
      if (x < a) l = 1;
    }
    if (u && d && r && l) cnt++;
  }
  cout << cnt << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(6);
  long long T = 1;
  while (T--) {
    solve();
  }
}
