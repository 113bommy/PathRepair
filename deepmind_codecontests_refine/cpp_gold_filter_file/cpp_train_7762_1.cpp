#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
void dout(string name, T arg) {
  cerr << arg << endl;
}
template <typename T1, typename... T2>
void dout(string names, T1 arg, T2... args) {
  cerr << arg << " | ";
  dout(names.substr(names.find(',') + 2), args...);
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mx = 1e3 + 5;
const int INF = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return (res % 1000000007);
}
vector<long long> adj[mx];
map<long long, long long> gov;
vector<long long> vis(mx, false);
class DSU {
 private:
  vector<long long> parent;
  vector<long long> sz;

 public:
  DSU(long long size) {
    parent.resize(size + 1);
    sz.resize(size + 1);
    for (int i = 1; i <= size; i++) {
      make_set(i);
    }
  }
  long long getSize(long long x) {
    long long p = this->find_parent(x);
    return sz[this->find_parent(x)];
  }
  void setParentSize(long long x) { sz[this->find_parent(x)] = 0; }
  void make_set(long long curr) {
    parent[curr] = curr;
    sz[curr] = 1;
  }
  long long find_parent(long long curr) {
    return (parent[curr] == curr) ? curr : find_parent(parent[curr]);
  }
  void union_set(long long x, long long y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x != y) {
      if (gov.find(x) != gov.end()) {
        sz[x] += sz[y];
        parent[y] = x;
      } else {
        sz[y] += sz[x];
        parent[x] = y;
      }
    }
  }
};
long long dfs(long long curr) {
  if (vis[curr]) return 0;
  vis[curr] = true;
  long long size = adj[curr].size();
  for (auto child : adj[curr]) {
    if (!vis[child]) size += dfs(child);
  }
  return size;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  DSU dsu(n);
  for (int i = 0; i < k; i++) {
    long long x;
    cin >> x;
    gov[x] = 0;
  }
  while (m--) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    dsu.union_set(a, b);
  }
  vector<long long> ref;
  long long maxSize = 0, ans = 0;
  vector<long long> extras;
  for (int i = 1; i <= n; i++) {
    if (gov.find(dsu.find_parent(i)) != gov.end()) {
      long long currSize = dsu.getSize(dsu.find_parent(i));
      dsu.setParentSize(i);
      long long totalSize = dfs(i);
      totalSize /= 2;
      ans += (currSize * (currSize - 1)) / 2 - totalSize;
      if (currSize > maxSize) {
        maxSize = currSize;
      }
    } else {
      long long currSize = dsu.getSize(i);
      ref.push_back(currSize);
      long long totalSize = dfs(i);
      totalSize /= 2;
      ans += currSize * (currSize - 1) / 2 - totalSize;
      dsu.setParentSize(i);
    }
  }
  for (int i = 0; i < ref.size(); i++) {
    ans += ref[i] * maxSize;
    maxSize += ref[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
