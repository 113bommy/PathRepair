#include <bits/stdc++.h>
using namespace std;
long long pow(long long b, long long e, long long m) {
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
template <typename T>
T gcd(T x, T y) {
  for (T t; x; t = x, x = y % x, y = t)
    ;
  return y;
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
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 220000;
int bit[maxn];
int top = 1;
void bit_modify(int k, int v) {
  for (; k < maxn; k += k & -k) bit[k] += v;
}
int bit_query(int k) {
  int t = bit[k];
  for (; k &= k - 1; t += bit[k])
    ;
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, t, a, x, k;
  cin >> n;
  double sum = 0;
  cout << setprecision(6);
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> a >> x;
      sum += (double)a * x;
      bit_modify(1, x);
      bit_modify(a + 1, -x);
    } else if (t == 2) {
      cin >> k;
      sum += k;
      ++top;
      bit_modify(top, k);
      bit_modify(top + 1, -k);
    } else if (t == 3) {
      int lx = bit_query(top);
      bit_modify(top, -lx);
      bit_modify(top + 1, lx);
      sum -= lx;
      --top;
    }
    cout << sum / top << endl;
  }
  return 0;
}
