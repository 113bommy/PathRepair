#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-8;
const int INF = (int)(2e9);
const long long mod = (int)(1e+9 + 7);
const int N = (int)(1e3);
int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2) {
  return make_pair(p1.first + p2.first, p1.second + p2.second);
}
int tam;
pair<int, int> route[2 * N + 1];
vector<pair<int, int> > route_;
vector<int> vec[N + 1];
pair<int, int> arr[N + 1];
bool vis[N + 1];
pair<int, int> dfs(int h) {
  vis[h] = true;
  route_.push_back(arr[h]);
  pair<int, int> sum = arr[h];
  for (int h2 : vec[h]) {
    if (vis[h2]) continue;
    sum = sum + dfs(h2);
  }
  return sum;
}
int nxt[2 * N + 1];
void add() {
  int it2 = tam + int(route_.size());
  for (pair<int, int> x : route_) {
    route[tam] = x;
    nxt[tam] = it2;
    tam++;
  }
}
bool used[2 * N + 1][N + 1];
int memo[2 * N + 1][N + 1];
int dp(int p, int w) {
  if (w < 0) return -INF;
  if (p == tam) return 0;
  if (used[p][w]) return memo[p][w];
  used[p][w] = true;
  int &ans = memo[p][w] = 0;
  ans = max(ans, dp(p + 1, w));
  ans = max(ans, route[p].second + dp(nxt[p], w - route[p].first));
  return ans;
}
int main() {
  int n, m, w;
  cin >> n >> m >> w;
  int a, b;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &arr[i].first);
  }
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &arr[i].second);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  for (int i = (1); i <= (n); i++) {
    if (vis[i]) continue;
    route_.clear();
    route_.push_back(dfs(i));
    add();
  }
  cout << dp(0, w);
  return 0;
}
