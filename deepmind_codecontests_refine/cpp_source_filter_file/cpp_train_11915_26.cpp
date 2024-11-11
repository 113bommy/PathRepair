#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long double PI = 3.14159265358979323846;
const long long MOD = 1e+9 + 7;
const long long INF = LLONG_MAX;
const int INFi = INT_MAX;
const long long N = 1e6 + 8;
vector<long long> adj[N];
long long vis[N];
long long dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
long long test_cases = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
;
long long n, m, k, p, a[1008][1008], row[N], col[N], pr[N], pc[N], res;
set<pair<long long, long long>, greater<pair<long long, long long>>> r, c;
void MAIN(long long tc) {
  cin >> n >> m >> k >> p;
  for (long long i = (1); i <= n; i++) {
    for (long long j = (1); j <= m; j++) {
      cin >> a[i][j];
      row[i] += a[i][j];
      col[j] += a[i][j];
    }
  }
  for (long long i = (1); i <= n; i++) r.insert({row[i], i});
  for (long long i = (1); i <= m; i++) c.insert({col[i], i});
  for (long long i = (1); i <= k; i++) {
    long long id = (*r.begin()).second;
    r.erase({row[id], id});
    pr[i] = pr[i - 1] + row[id];
    row[id] -= p * m;
    r.insert({row[id], id});
  }
  for (long long i = (1); i <= k; i++) {
    long long id = (*c.begin()).second;
    c.erase({col[id], id});
    pc[i] = pc[i - 1] + col[id];
    col[id] -= p * n;
    c.insert({col[id], id});
  }
  for (long long i = (0); i <= k; i++)
    res = max(res, pr[i] + pc[k - i] - p * i * (k - i));
  cout << res << " ";
  cout << "\n";
  ;
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  for (long long i = (1); i <= test_cases; i++) {
    MAIN(i);
  }
}
