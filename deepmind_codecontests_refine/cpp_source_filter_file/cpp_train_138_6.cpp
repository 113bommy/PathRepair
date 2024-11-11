#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
map<pair<long long int, long long int>, long long int> m;
string s;
vector<long long int> a;
void bfs(long long int x, long long int y, long long int x1, long long int y1) {
  std::queue<pair<long long int, pair<long long int, long long int>>> q;
  q.push({0, {x, y}});
  vector<pair<long long int, long long int>> dr;
  dr.push_back({1, 0});
  dr.push_back({-1, 0});
  dr.push_back({0, 1});
  dr.push_back({0, -1});
  dr.push_back({1, 1});
  dr.push_back({-1, -1});
  dr.push_back({-1, 1});
  dr.push_back({1, 1});
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    auto it = m.find(u.second);
    if (it == m.end() || it->second <= u.first) continue;
    ;
    if (x1 == u.second.first && y1 == u.second.second) {
      cout << u.first << "\n";
      exit(0);
    }
    it->second = u.first;
    for (auto dx : dr)
      q.push({u.first + 1,
              {u.second.first + dx.first, u.second.second + dx.second}});
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long int x0, x1, y0, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    while (n--) {
      cin >> r >> x >> y;
      for (i = (x); i <= (y); ++i) m[make_pair(r, i)] = INF;
    }
    bfs(x0, y0, x1, y1);
    ;
    cout << -1 << "\n";
  }
  aryanc403();
  return 0;
}
