#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName) {
  if (fileName.empty()) return;
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
  return;
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10;
const int N = 2e5 + 1000, P = 450;
int n;
vector<int> X, Y;
int a[N], b[N], c[N], d[N];
int minv[400], dist[N], pre[N];
multimap<int, int> p[N];
bool update[P];
void get(int x, int y, vector<int>& res) {
  memset(update, 0, sizeof update);
  for (int i = 0; i <= x; i++) {
    if (minv[i / P] > y) {
      i += P - 1;
      continue;
    }
    if (p[i].empty()) continue;
    while (!p[i].empty() && p[i].begin()->first <= y) {
      res.push_back(p[i].begin()->second);
      p[i].erase(p[i].begin());
    }
    update[i / P] = 1;
  }
  for (int i = 0; i <= ((X.size() - 1) / P); i++) {
    if (update[i]) {
      minv[i] = INF;
      for (int j = i * P; j < i * P + P && j < X.size(); j++) {
        if (p[j].empty()) continue;
        minv[i] = min(minv[i], p[j].begin()->first);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  EnableFileIO("");
  queue<int> que;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    X.push_back(a[i]), X.push_back(c[i]);
    minv[i / P] = INF, dist[i] = INF;
    if (a[i] == 0 && b[i] == 0) {
      que.push(i);
      dist[i] = 1, pre[i] = -1;
    }
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  for (int i = 0; i < n; i++) {
    a[i] = (int)(lower_bound(X.begin(), X.end(), a[i]) - X.begin());
    c[i] = (int)(lower_bound(X.begin(), X.end(), c[i]) - X.begin());
    if (pre[i] == -1) continue;
    p[a[i]].insert(make_pair(b[i], i)),
        minv[a[i] / P] = min(minv[a[i] / P], b[i]);
  }
  while (!que.empty()) {
    vector<int> nxt;
    nxt.clear();
    int id = que.front();
    int x = c[id], y = d[id];
    que.pop();
    get(x, y, nxt);
    for (int i = 0; i < nxt.size(); i++) {
      if (dist[nxt[i]] != INF) continue;
      dist[nxt[i]] = dist[id] + 1, pre[nxt[i]] = id;
      que.push(nxt[i]);
    }
  }
  if (dist[n - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[n - 1] << endl;
    stack<int> ans;
    int p = n - 1;
    while (p != -1) {
      ans.push(p);
      p = pre[p];
    }
    assert(ans.size() == dist[n - 1]);
    while (!ans.empty()) {
      cout << ans.top() + 1 << ' ';
      ans.pop();
    }
    cout << endl;
  }
  return 0;
}
