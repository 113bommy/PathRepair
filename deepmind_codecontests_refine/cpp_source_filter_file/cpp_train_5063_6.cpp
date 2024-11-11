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
const int maxn = 55;
int n, h;
long long k;
int s[maxn];
long long calc(long long x) {
  long long ret = (x + 1) * ((1ll << h) - x);
  if (n & 1) ret = ret * 2 - x - 1;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  k += 1;
  h = n >> 1;
  long long L = 0, R = (1ll << h) - 1, mid;
  for (; mid = (L + R) >> 1, L < R;) calc(mid) >= k ? (R = mid) : (L = mid + 1);
  if (calc(mid) < k) return cout << -1 << endl, 0;
  for (int i = h - 1; i >= 0; --i) cout << ((L >> i) & 1);
  L = mid, R = (1 << h) - 1 - mid;
  k -= calc(mid - 1);
  if (n & 1) {
    if (k > (1 << h) - 2 * mid)
      cout << 1, k -= (1 << h) - 2 * mid;
    else
      cout << 0;
  }
  for (int i = 0; i < h; ++i) {
    if ((R >> 1) - ((L + 1) >> 1) + 1 >= k)
      cout << 0, L = (L + 1) >> 1, R >>= 1;
    else
      cout << 1, k -= (R >> 1) - ((L + 1) >> 1) + 1, L = L >> 1,
                                                     R = (R - 1) >> 1;
  }
  cout << endl;
  return 0;
}
