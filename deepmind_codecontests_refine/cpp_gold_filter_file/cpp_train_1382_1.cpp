#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long double EPS = 1e-4;
vector<int> primes(1, 2);
vector<vector<long double>> nk;
void sieve() {
  vector<int> m(N + 1, 0);
  for (int i = 4; i < N; i += 2) m[i] = 1;
  for (int i = 3; i * i <= N; i += 2)
    if (!m[i])
      for (int j = i * i; j < N; j += i) m[j] = 1;
  for (int i = 3; i < N; i += 2)
    if (!m[i]) primes.push_back(i);
}
void pascal() {
  nk = vector<vector<long double>>(N, vector<long double>(N, 0.0));
  for (int i = (0), ThxMK = (N); i < ThxMK; ++i) nk[i][0] = nk[i][i] = 1.0;
  for (int i = (1), ThxMK = (N); i < ThxMK; ++i)
    for (int j = (1), ThxMK = (i); j < ThxMK; ++j)
      nk[i][j] = nk[i - 1][j - 1] + nk[i - 1][j];
}
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long lcm(long long a, long long b) {
  if (a < b) swap(a, b);
  long long c = gcd(a, b);
  a /= c;
  return a * b;
}
int popcount(long long x) { return __builtin_popcountll(x); }
long long poww(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return res;
}
bool isPrime(long long x) {
  if (x == 1) return 0;
  for (auto i : primes) {
    if (i * i > x) return 1;
    if (x % i == 0) return 0;
  }
  return 1;
}
long long SUM(long long a, long long b, long long mod = MOD) {
  return (a + b + mod) % mod;
}
long long PROD(long long a, long long b, long long mod = MOD) {
  a %= mod;
  b %= mod;
  return a * b % mod;
}
int dx[4] = {1, -1, 1, -1}, dy[4] = {1, -1, -1, 1};
vector<vector<int>> graph(int n, int m) {
  vector<vector<int>> v(n + 1, vector<int>(0));
  for (int i = (0), ThxMK = (m); i < ThxMK; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  return v;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> v(n + 1, vector<vector<int>>(2, vector<int>()));
  for (int i = (0), ThxMK = (m); i < ThxMK; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[b][c].push_back(a);
  }
  vector<long long> dis(n + 1, INF);
  vector<int> color(n + 1, -1);
  vector<pair<int, int>> pr(n + 1, {0, 0});
  queue<int> q;
  dis[n] = 0;
  q.push(n);
  while (!q.empty()) {
    auto a = q.front();
    q.pop();
    for (int j = (0), ThxMK = (2); j < ThxMK; ++j)
      for (auto i : v[a][j]) {
        if (dis[i] < INF) continue;
        if (color[i] == -1)
          color[i] = !j;
        else {
          if (j != color[i]) continue;
          q.push(i);
          dis[i] = dis[a] + 1;
        }
      }
  }
  if (dis[1] == INF)
    cout << -1 << '\n';
  else
    cout << dis[1] << '\n';
  for (int i = (1), ThxMK = (n + 1); i < ThxMK; ++i) cout << max(color[i], 0);
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
