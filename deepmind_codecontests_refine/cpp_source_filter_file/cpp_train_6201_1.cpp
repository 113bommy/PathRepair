#include <bits/stdc++.h>
using namespace std;
namespace {
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
long long int expmod(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
template <typename T>
void sort(T& t) {
  sort(begin(t), end(t));
}
struct IOS {
  IOS() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
} IOS;
}  // namespace
const long long int MOD = 1000000009LL;
const long long int INF = LLONG_MAX / 2;
const double EPS = 1e-8;
int n, m, k;
tuple<int, pair<long long int, long long int>,
      pair<long long int, long long int>>
nxt(const pair<long long int, long long int>& pos,
    const pair<long long int, long long int>& grad) {
  int best = INT_MAX;
  pair<long long int, long long int> best_grad = {0, 0};
  int t = -pos.first / grad.first;
  if (t > 0 && t < best) {
    best = t;
    best_grad = {-grad.first, grad.second};
  }
  t = (n - pos.first) / grad.first;
  if (t > 0 && t < best) {
    best = t;
    best_grad = {-grad.first, grad.second};
  }
  t = -pos.second / grad.second;
  if (t > 0 && t < best) {
    best = t;
    best_grad = {grad.first, -grad.second};
  }
  t = (m - pos.second) / grad.second;
  if (t > 0 && t < best) {
    best = t;
    best_grad = {grad.first, -grad.second};
  }
  t = best;
  return make_tuple(
      t, make_pair(pos.first + t * grad.first, pos.second + t * grad.second),
      best_grad);
}
double dist(const pair<long long int, long long int>& a,
            const pair<long long int, long long int>& b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
bool point_on_line(const pair<long long int, long long int>& a,
                   const pair<long long int, long long int>& b,
                   const pair<long long int, long long int>& c) {
  return abs(dist(a, c) + dist(c, b) - dist(a, b)) < EPS;
}
int main() {
  cin >> n >> m >> k;
  pair<long long int, long long int> pos = {0, 0};
  pair<long long int, long long int> grad = {1, 1};
  map<pair<long long int, long long int>, vector<int>> sensor;
  vector<pair<long long int, long long int>> sensor_locs;
  vector<long long int> ans(k, INT_MAX);
  vector<pair<long long int, long long int>> dirs = {
      {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
  for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
       i += 1 - 2 * ((0) > (k))) {
    long long int x, y;
    cin >> x >> y;
    long long int dt;
    pair<long long int, long long int> npos, ngrad;
    for (auto& d : dirs) {
      tie(dt, npos, ngrad) = nxt({x, y}, d);
      sensor[npos].push_back(i);
    }
    sensor_locs.emplace_back(x, y);
  }
  map<pair<long long int, long long int>, bool> vis;
  vis[{n, m}] = true;
  vis[{0, m}] = true;
  vis[{n, 0}] = true;
  long long int t = 0;
  while (!vis[pos]) {
    vis[pos] = true;
    long long int dt;
    pair<long long int, long long int> npos, ngrad;
    tie(dt, npos, ngrad) = nxt(pos, grad);
    for (auto& s : sensor[npos]) {
      if (!point_on_line(pos, npos, sensor_locs[s])) continue;
      long long int hit_time =
          t + (sensor_locs[s].first - pos.first) / grad.first;
      ans[s] = min(ans[s], hit_time);
    }
    t += dt;
    pos = npos;
    grad = ngrad;
  }
  for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
       i += 1 - 2 * ((0) > (k)))
    if (ans[i] == INT_MAX)
      cout << -1 << '\n';
    else
      cout << ans[i] << '\n';
}
