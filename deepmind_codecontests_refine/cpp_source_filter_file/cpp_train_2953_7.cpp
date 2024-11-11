#include <bits/stdc++.h>
using namespace std;
struct heap {
  vector<pair<int, int> > v;
  int loc[100005];
  heap() {
    v.push_back(make_pair(-1, -1));
    memset(loc, -1, sizeof(loc));
  }
  void push(pair<int, int> p) {
    int cur;
    if (loc[p.second] >= 0) {
      cur = loc[p.second];
      v[cur].first = min(v[cur].first, p.first);
    } else {
      cur = v.size();
      loc[p.second] = cur;
      v.push_back(p);
    }
    while (v[cur] < v[cur / 2]) {
      swap(v[cur], v[cur / 2]);
      swap(loc[v[cur].second], loc[v[cur / 2].second]);
      cur /= 2;
    }
  }
  void pop() {
    if (empty()) return;
    swap(v[1], v.back());
    loc[v[1].second] = 1;
    loc[v.back().second] = -1;
    v.pop_back();
    int cur = 1;
    while (2 * cur < v.size()) {
      if (2 * cur + 1 == v.size()) {
        if (v[cur] > v[2 * cur]) {
          swap(v[cur], v[2 * cur]);
          swap(loc[v[cur].second], loc[v[2 * cur].second]);
        }
        break;
      }
      if (v[cur] < min(v[2 * cur], v[2 * cur + 1])) break;
      if (v[2 * cur] < v[2 * cur + 1]) {
        swap(v[cur], v[2 * cur]);
        swap(loc[v[cur].second], loc[v[2 * cur].second]);
        cur * 2;
      } else {
        swap(v[cur], v[2 * cur + 1]);
        swap(loc[v[cur].second], loc[v[2 * cur + 1].second]);
        cur = 2 * cur + 1;
      }
    }
  }
  pair<int, int> top() { return v[1]; }
  bool empty() { return v.size() == 1; }
  void print() {
    for (int i = 1; i < v.size(); i++)
      cout << v[i].second << " " << v[i].first << endl;
    cout << endl;
  }
};
int n, m, j, a, dist[100005], cur, next, t;
bool vis[100005];
vector<pair<int, int> > adj[100005];
vector<int> bad[100005];
heap pq;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  for (int i = 0; i < n; i++) {
    cin >> j;
    for (int k = 0; k < j; k++) {
      cin >> a;
      bad[i].push_back(a);
    }
  }
  dist[n - 1] = 2000000000;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    t = pq.top().first;
    cur = pq.top().second;
    pq.pop();
    if (vis[cur]) continue;
    dist[cur] = t;
    vis[cur] = 1;
    j = 0;
    while (j < bad[cur].size() && bad[cur][j] < t) j++;
    while (j < bad[cur].size() && bad[cur][j] == t) {
      j++;
      t++;
    }
    for (int i = 0; i < adj[cur].size(); i++) {
      if (!vis[adj[cur][i].first]) {
        pq.push(make_pair(t + adj[cur][i].second, adj[cur][i].first));
      }
    }
  }
  if (dist[n - 1] < 2000000000)
    cout << dist[n - 1] << endl;
  else
    cout << -1 << endl;
  return 0;
}
