#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sign(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dyK[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dxKn[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dyKn[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int N = int(2e2) + 9;
const int M = N * N / 2;
const int LOGN = 22;
const int SQN = 350;
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 100;
const long long INF64 = 2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
int h, t, r;
int n, m;
pair<int, int> a[N];
pair<int, int> b[N];
int u[N][N];
int d[N][N];
int dp[N][N];
void dfs(int curH, int curT) {
  u[curH][curT] = 1;
  for (int i = 1; i < (int)(min(curH + 1, n + 1)); ++i) {
    int nh = curH - i + a[i].first;
    int nt = curT + a[i].second;
    if (nh + nt > r) continue;
    if (!u[nh][nt])
      dfs(nh, nt);
    else if (u[nh][nt] == 1) {
      cout << "Draw";
      exit(0);
    }
  }
  for (int i = 1; i < (int)(min(curT + 1, m + 1)); ++i) {
    int nh = curH + b[i].first;
    int nt = curT - i + b[i].second;
    if (nh + nt > r) continue;
    if (!u[nh][nt])
      dfs(nh, nt);
    else if (u[nh][nt] == 1) {
      cout << "Draw";
      exit(0);
    }
  }
  u[curH][curT] = 2;
}
int calc_dp(int curH, int curT) {
  int &res = dp[curH][curT];
  if (res != -1) return res;
  res = 1;
  for (int i = 1; i < (int)(min(curH + 1, n + 1)); ++i) {
    int nh = curH - i + a[i].first;
    int nt = curT + a[i].second;
    if (nh + nt > r) continue;
    res = max(res, 1 + calc_dp(nh, nt));
  }
  for (int i = 1; i < (int)(min(curT + 1, m + 1)); ++i) {
    int nh = curH + b[i].first;
    int nt = curT - i + b[i].second;
    if (nh + nt > r) continue;
    res = max(res, 1 + calc_dp(nh, nt));
  }
  return res;
}
void solve() {
  for (int i = 0; i < (int)(N); ++i)
    for (int j = 0; j < (int)(N); ++j) d[i][j] = INF;
  cin >> h >> t >> r;
  cin >> n;
  for (int i = 1; i < (int)(n + 1); ++i) cin >> a[i].first >> a[i].second;
  cin >> m;
  for (int i = 1; i < (int)(m + 1); ++i) cin >> b[i].first >> b[i].second;
  queue<pair<int, int> > q;
  d[h][t] = 0;
  q.push(make_pair(h, t));
  while (!q.empty()) {
    pair<int, int> v = q.front();
    q.pop();
    for (int i = 1; i < (int)(min(v.first + 1, n + 1)); ++i) {
      int nh = v.first - i + a[i].first;
      int nt = v.second + a[i].second;
      if (nh + nt <= r && d[nh][nt] == INF) {
        d[nh][nt] = d[v.first][v.second] + 1;
        q.push(make_pair(nh, nt));
      }
    }
    for (int i = 1; i < (int)(min(v.second + 1, m + 1)); ++i) {
      int nh = v.first + b[i].first;
      int nt = v.second - i + b[i].second;
      if (nh + nt <= r && d[nh][nt] == INF) {
        d[nh][nt] = d[v.first][v.second] + 1;
        q.push(make_pair(nh, nt));
      }
    }
  }
  if (d[0][0] != INF) {
    cout << "Ivan\n";
    cout << d[0][0];
    return;
  }
  dfs(h, t);
  memset(dp, -1, sizeof dp);
  cout << "Zmey\n";
  cout << calc_dp(h, t);
}
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  solve();
  return 0;
}
