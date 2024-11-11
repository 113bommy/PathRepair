#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 200007;
vector<pair<int, int> > e[maxn];
int sz[maxn], n;
bool vis[maxn];
pair<long long, int> tmp[maxn];
long long l, w, ans = 0;
void calcSize(int u, int fa) {
  sz[u] = 1;
  int n = e[u].size();
  vector<pair<int, int> > &v = e[u];
  for (int i = 0; i < n; ++i)
    if (!vis[v[i].first] && v[i].first != fa) {
      calcSize(v[i].first, u);
      sz[u] += sz[v[i].first];
    }
}
int findCenter(int u, int fa, int size) {
  int maxpart = size - sz[u], n = e[u].size();
  vector<pair<int, int> > &v = e[u];
  for (int i = 0; i < n; ++i)
    if (!vis[v[i].first] && v[i].first != fa)
      maxpart = max(maxpart, sz[v[i].first]);
  if (maxpart * 2 <= size) return u;
  for (int t, i = 0; i < n; ++i)
    if (!vis[v[i].first] && v[i].first != fa) {
      t = findCenter(v[i].first, u, size);
      if (t != -1) return t;
    }
  return -1;
}
int getCenter(int u) {
  calcSize(u, -1);
  return findCenter(u, -1, sz[u]);
}
void getLength(int u, int fa, int distance, pair<long long, int> dist[],
               int &top, int depth) {
  if (depth <= l && distance <= w) ++ans;
  dist[top++] = make_pair(distance, depth);
  int n = e[u].size();
  vector<pair<int, int> > &v = e[u];
  for (int i = 0; i < n; ++i)
    if (!vis[v[i].first] && v[i].first != fa)
      getLength(v[i].first, u, distance + v[i].second, dist, top, depth + 1);
}
pair<long long, int> res[maxn];
struct Event {
  int x, k;
  Event(int x, int k) : x(x), k(k) {}
  bool operator<(const Event &o) const { return x < o.x; }
};
int BIT[maxn];
void add(int x, int y) {
  ++x;
  while (x <= n + 10) {
    BIT[x] += y;
    x += x & -x;
  }
}
int sum(int x) {
  ++x;
  int ret = 0;
  while (x) {
    ret += BIT[x];
    x -= x & -x;
  }
  return ret;
}
long long getValidPairs(pair<long long, int> d[], int limit, int l, int r) {
  int total = 0;
  for (int i = l; i <= r; ++i) {
    res[total++] = d[i];
  }
  vector<pair<int, int> > event;
  int ptr = total - 1;
  for (int i = 0; i < total; ++i) {
    while (ptr > i && res[i].first + res[ptr].first > limit) --ptr;
    if (ptr <= i) break;
    if (i < ptr && res[i].second < ::l &&
        res[i].first + res[ptr].first <= limit) {
      event.push_back(make_pair(i, -(::l - res[i].second)));
      event.push_back(make_pair(ptr, ::l - res[i].second));
    }
  }
  sort(event.begin(), event.end());
  long long ret = 0;
  ptr = 0;
  for (int i = 0; i < total; ++i) {
    add(res[i].second, 1);
    while (ptr < event.size() && event[ptr].first <= i) {
      int t = event[ptr].second;
      if (t < 0) {
        ret -= sum(abs(t));
      } else {
        ret += sum(abs(t));
      }
      ++ptr;
    }
  }
  while (ptr < event.size()) {
    int t = event[ptr].second;
    if (t < 0) {
      ret -= sum(abs(t));
    } else {
      ret += sum(abs(t));
    }
    ++ptr;
  }
  for (int i = 0; i < total; ++i) {
    add(res[i].second, -1);
  }
  return ret;
}
void solve(int u) {
  u = getCenter(u);
  vis[u] = true;
  int n = e[u].size();
  vector<pair<int, int> > &v = e[u];
  int cnt = 0, prev = 0;
  long long part = 0;
  for (int i = 0; i < n; ++i)
    if (!vis[v[i].first]) {
      getLength(v[i].first, u, v[i].second, tmp, cnt, 1);
      sort(tmp + prev, tmp + cnt);
      part += getValidPairs(tmp, w, prev, cnt - 1);
      prev = cnt;
    }
  sort(tmp, tmp + cnt);
  ans += getValidPairs(tmp, w, 0, cnt - 1) - part;
  for (int i = 0; i < n; ++i)
    if (!vis[v[i].first]) solve(v[i].first);
}
int main() {
  cin >> n >> l >> w;
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    scanf("%d%d", &u, &t);
    --u;
    v = i + 1;
    e[u].push_back(make_pair(v, t));
    e[v].push_back(make_pair(u, t));
  }
  solve(0);
  cout << ans << endl;
  return 0;
}
