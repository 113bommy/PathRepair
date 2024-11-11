#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > g;
vector<int> dist;
vector<int> backward;
void dijkstra(int s) {
  int n = g.size();
  vector<int> visited(n);
  dist.clear();
  dist.resize(n, -1);
  backward.clear();
  backward.resize(n, -1);
  dist[s] = 0;
  visited[s] = 1;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int now = q.top().second;
    q.pop();
    if (visited[now] == 2) continue;
    visited[now] = 2;
    for (int i = 0; i < g[now].size(); i++) {
      int next = g[now][i].first;
      int dv = dist[now] + g[now][i].second;
      if (dv < dist[next] || dist[next] == -1) {
        dist[next] = dv;
        visited[next] = 1;
        q.push(make_pair(dist[next], next));
        backward[next] = now;
      }
    }
  }
}
int main() {
  int n, l;
  while (cin >> n >> l) {
    g.clear();
    g.resize(2 * n + 2);
    vector<pair<int, int> > v;
    vector<int> x(n);
    vector<int> d(n);
    vector<int> t(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> d[i] >> t[i] >> p[i];
      if (x[i] - p[i] >= 0) {
        g[2 * i].push_back(make_pair(2 * i + 1, p[i] + t[i]));
        v.push_back(make_pair(x[i] - p[i], 2 * i));
        v.push_back(make_pair(x[i] + d[i], 2 * i + 1));
        g[2 * n].push_back(make_pair(2 * i, x[i] - p[i]));
      }
    }
    v.push_back(make_pair(0, 2 * n));
    v.push_back(make_pair(l, 2 * n + 1));
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size() - 1; i++) {
      int front = v[i].second;
      int coordFront = v[i].first;
      int back = v[i + 1].second;
      int coordBack = v[i + 1].first;
      g[front].push_back(make_pair(back, coordBack - coordFront));
      g[back].push_back(make_pair(front, coordBack - coordFront));
    }
    dijkstra(2 * n);
    cout << dist[2 * n + 1] << endl;
    vector<int> ramp;
    int now = 2 * n + 1;
    while (now != 2 * n) {
      int prev = backward[now];
      if (now / 2 == prev / 2) {
        int idx = now / 2;
        if (idx != n && t[idx] < d[idx]) {
          ramp.push_back(idx);
        }
      }
      now = prev;
    }
    sort(ramp.begin(), ramp.end());
    cout << ramp.size() << endl;
    for (int i = 0; i < ramp.size(); i++) {
      cout << ramp[i] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
