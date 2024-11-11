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
long long mod, L, R, K, ans = 1;
void update(long long t) {
  if (t > ans && R / t - L / t >= K) ans = t;
}
void work(long long w) {
  for (long long x = w + 1; x;) {
    update(x), update(x + 1);
    x = w / (w / x + 1);
  }
}
pair<long long, long long> fib(long long w) {
  if (w == 1) return make_pair(0ll, 1ll);
  pair<long long, long long> t, k;
  if (w & 1)
    return t = fib(w - 1), make_pair(t.second, (t.first + t.second) % mod);
  t = fib(w / 2),
  k.first = (t.first * t.first % mod + t.second * t.second % mod) % mod;
  return k.second = t.second * (t.second + 2 * t.first) % mod, k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> mod >> L >> R >> K;
  --L;
  work(L), work(R);
  cout << fib(ans).second % mod << endl;
  return 0;
}
