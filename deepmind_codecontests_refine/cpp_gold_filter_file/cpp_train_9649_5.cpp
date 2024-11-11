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
vector<pair<int, int> > ans;
vector<int> vec;
void move_partial(int, int, int, int);
void move_optimal(int d, int x, int y, int z) {
  if (vec[d] == 1) return move_partial(d, x, y, z);
  if (d == (int)((vec).size()) - 1) {
    for (int i = 1; i < vec[d]; ++i) ans.push_back(make_pair(x, z));
    ans.push_back(make_pair(x, y));
    for (int i = 1; i < vec[d]; ++i) ans.push_back(make_pair(z, y));
    return;
  }
  move_partial(d + 1, x, y, z);
  for (int i = 1; i <= vec[d]; ++i) ans.push_back(make_pair(x, z));
  move_partial(d + 1, y, x, z);
  for (int i = 1; i <= vec[d]; ++i) ans.push_back(make_pair(z, y));
  move_optimal(d + 1, x, y, z);
}
void move_partial(int d, int x, int y, int z) {
  if (d == (int)((vec).size())) return;
  move_partial(d + 1, x, z, y);
  for (int i = 1; i <= vec[d]; ++i) ans.push_back(make_pair(x, y));
  move_partial(d + 1, z, y, x);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, lx = 0;
  cin >> n;
  for (int i = 1, d; i <= n; ++i) {
    cin >> d;
    if (lx == d)
      ++vec[(int)((vec).size()) - 1];
    else
      vec.push_back(1);
    lx = d;
  }
  move_optimal(0, 1, 3, 2);
  cout << (int)((ans).size()) << endl;
  for (__typeof__((ans).begin()) it = (ans).begin(); it != (ans).end(); ++it)
    cout << it->first << " " << it->second << endl;
  return 0;
}
