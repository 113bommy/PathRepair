#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a > b ? a = b, true : false;
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
  void adde(int s, edge e) { adj[s].push_back(e); }
  typename vector<edge>::iterator operator[](int t) { return adj[t].begin(); }
};
const int maxn = 110000;
int n;
long long bit[33][maxn];
int a[maxn];
void modify(long long *bit, int x, int v) {
  for (; x <= n; x += x & -x) bit[x] += v;
}
long long query(long long *bit, int x) {
  long long t = 0;
  for (; x; x &= x - 1) t += bit[x];
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 2; j <= 6; ++j)
      modify(bit[(((j)-2) * ((j)-1) + ((((i)-1) % (2 * (j)-2))))], i, a[i]);
  }
  int m, cmd, l, r, z;
  cin >> m;
  for (; m--;) {
    cin >> cmd;
    if (cmd == 1) {
      int p, v;
      cin >> p >> v;
      for (int j = 2; j <= 6; ++j)
        modify(bit[(((j)-2) * ((j)-1) + ((((p)-1) % (2 * (j)-2))))], p,
               v - a[p]);
      a[p] = v;
    } else {
      cin >> l >> r >> z;
      long long ans = 0;
      for (int k = 0; k < 2 * z - 2; ++k) {
        int nk = (l - 1 + k) % (2 * z - 2);
        ans += (query(bit[(((z)-2) * ((z)-1) + (nk))], r) -
                query(bit[(((z)-2) * ((z)-1) + (nk))], l - 1)) *
               (k >= z ? (2 * z - 1 - k) : (k + 1));
      }
      cout << ans << endl;
    }
  }
  return 0;
}
