#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005;
const int INF = (1 << 30);
const int MOD = 1000000007;
const int BLOCK = 101;
vector<pair<int, int> > v[NMAX];
pair<int, int> pex[NMAX];
pair<int, int> pey[NMAX];
int dist[NMAX];
int inq[NMAX];
struct cmp {
  bool operator()(int a, int b) { return dist[a] < dist[b]; }
};
map<int, pair<int, int> > mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, n, m, x1, x2, y1, y2;
  cin >> n >> m;
  cin >> x1 >> y1 >> x2 >> y2;
  for (i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    mp[i] = {a, b};
    pex[i] = {a, i};
    pey[i] = {b, i};
  }
  pex[m + 1] = {x1, m + 1};
  pey[m + 1] = {y1, m + 1};
  mp[m + 1] = {x1, y1};
  m++;
  sort(pex + 1, pex + m + 1);
  sort(pey + 1, pey + m + 1);
  for (i = 1; i < m; i++) {
    int b = pex[i].second;
    int c = pex[i + 1].second;
    int c2 = pex[i + 1].first - pex[i].first;
    v[b].push_back({c, c2});
    v[c].push_back({b, c2});
  }
  for (i = 1; i < m; i++) {
    int b = pey[i].second;
    int c = pey[i + 1].second;
    int c2 = pey[i + 1].first - pey[i].first;
    v[b].push_back({c, c2});
    v[c].push_back({b, c2});
  }
  priority_queue<pair<int, int> > pq;
  for (i = 0; i <= m + 1; i++) dist[i] = INF;
  dist[m] = 0;
  pq.push({-dist[i], m});
  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    if (!inq[node]) {
      inq[node] = 1;
      for (auto x : v[node]) {
        int a = x.first;
        int c = x.second;
        if (dist[a] > c + dist[node]) {
          dist[a] = c + dist[node];
          pq.push({dist[a], a});
        }
      }
    }
  }
  int minim = abs(x2 - x1) + abs(y2 - y1);
  for (i = 1; i <= m - 1; i++) {
    minim =
        min(minim, dist[i] + abs(mp[i].first - x2) + abs(mp[i].second - y2));
  }
  cout << minim;
  return 0;
}
