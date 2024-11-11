#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) {
    adj[s].erase(find((adj[s]).begin(), (adj[s]).end(), e));
  }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 110000;
int n, m;
int a[maxn], pred[maxn], succ[maxn];
vector<int> pos;
int sz;
long long calc(int L) {
  long long ret = 0, now = 0;
  set<int> S;
  S.insert(n + 1);
  for (int x = sz; x > L; --x) {
    long long t = pos[x] - pos[x - 1] - 1;
    now += t * (t + 1) / 2;
    S.insert(pos[x - 1]);
    if (pos[x] <= n && pred[pos[x]] < pos[L])
      for (int i = pos[x]; i; i = succ[i]) {
        auto it = S.find(i), pre = it, nxt = it;
        int a = *--pre, b = *++nxt;
        now += (i - a) * (b - i);
        S.erase(it);
      }
    long long w = *++S.begin() - *S.begin() - 1;
    ret += (t + 1) * (now - w * (w + 1) / 2) + w * (w + 1) * (w + 2) / 6 -
           (w - t + 1) * (w - t) * (w - t - 1) / 6;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  unordered_map<int, int> f;
  pos.push_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    succ[pred[i] = f[a[i]]] = i;
    f[a[i]] = i;
    for (int x = a[i]; x; x /= 10)
      if (x % 10 != 4 && x % 10 != 7) pred[i] = -1;
    if (pred[i] != -1) pos.push_back(i);
  }
  sz = (int)((pos).size());
  long long ans = 0;
  pos.push_back(n + 1);
  for (int i = 1; i < sz; ++i) ans += (pos[i] - pos[i - 1]) * calc(i);
  ({});
  for (int i = 1; i <= sz; ++i)
    for (int x = pos[i - 1] + 1; x < pos[i]; ++x)
      ans += (n - x + 1ll) * (n - x) / 2 * (x - pos[i - 1]);
  cout << ans << endl;
  return 0;
}
