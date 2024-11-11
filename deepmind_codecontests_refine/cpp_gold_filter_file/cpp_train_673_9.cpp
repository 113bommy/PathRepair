#include <bits/stdc++.h>
using namespace std;
long long cnt_up[100001], cnt_st[100001], cnt_end[100001];
template <int _MAXN, int _MAXLOGN>
class LCA {
 public:
  struct Edge {
    int x, dd;
    Edge(int a = 0, int b = 0) : x(a), dd(b) {}
  };
  int rmq[_MAXLOGN][_MAXN << 1];
  int vs[_MAXN << 1], d[_MAXN << 1], first[_MAXN];
  vector<Edge> e[_MAXN];
  int cnt;
  void init(int n) {
    for (int i = 0; i <= n; ++i) e[i].clear();
    cnt = 0;
  }
  void addedge(int x, int y, int dd) { e[x].push_back(Edge(y, dd)); }
  void dfs(int k, int dep, int pa) {
    first[k] = cnt, d[cnt] = dep, vs[cnt++] = k;
    for (auto &i : e[k]) {
      if (i.x != pa) {
        dfs(i.x, dep + 1, k);
        d[cnt] = dep;
        vs[cnt++] = k;
      }
    }
  }
  void initRMQ() {
    for (int i = 0; i < cnt; ++i) rmq[0][i] = i;
    for (int j = 1; (1 << j) <= cnt; ++j)
      for (int i = 0; i + (1 << j) <= cnt; ++i)
        rmq[j][i] = d[rmq[j - 1][i]] < d[rmq[j - 1][i + (1 << (j - 1))]]
                        ? rmq[j - 1][i]
                        : rmq[j - 1][i + (1 << (j - 1))];
  }
  int query(int a, int b) {
    int k = __builtin_clz((int)1) - __builtin_clz(b - a + 1);
    return d[rmq[k][a]] < d[rmq[k][b - (1 << k) + 1]]
               ? rmq[k][a]
               : rmq[k][b - (1 << k) + 1];
  }
  int find_lca(int a, int b) {
    if (first[a] > first[b]) swap(a, b);
    return vs[query(first[a], first[b])];
  }
};
inline void getd(int &d) {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  d = 0;
  do {
    (d *= 10) += ch - '0';
  } while (isdigit(ch = getchar()));
}
long long big_mod(long long a, long long n, long long p) {
  if (n == 0) return 1LL;
  long long tmp = big_mod(a, n >> 1, p);
  return tmp * tmp % p * (n & 1 ? a : 1) % p;
}
LCA<100001, 19> lca;
long long sum_up(int k, int pa) {
  long long sum = 0;
  for (auto &i : lca.e[k]) {
    if (i.x != pa) {
      sum = (sum + sum_up(i.x, k)) % 1000000007;
      cnt_st[k] += cnt_st[i.x];
      cnt_up[k] += cnt_up[i.x];
      cnt_end[k] += cnt_end[i.x];
    }
  }
  for (auto &i : lca.e[k]) {
    if (i.dd == 2) {
      long long x =
          i.x == pa ? cnt_st[k] - cnt_up[k] : cnt_end[i.x] - cnt_up[i.x];
      sum = (sum + big_mod(2, x, 1000000007) - 1 + 1000000007) % 1000000007;
    }
  }
  return sum;
}
int main() {
  int n;
  getd(n);
  lca.init(n);
  for (int i = 0; i < (int)(n - 1); i++) {
    int a, b, dd;
    getd(a), getd(b), getd(dd);
    if (dd == 0) {
      lca.addedge(a, b, 0);
      lca.addedge(b, a, 0);
    } else {
      lca.addedge(a, b, 1);
      lca.addedge(b, a, 2);
    }
  }
  lca.dfs(1, 0, 0);
  lca.initRMQ();
  int s = 1, q;
  getd(q);
  while (q--) {
    int x;
    getd(x);
    int k = lca.find_lca(s, x);
    cnt_st[s]++;
    cnt_up[k]++;
    cnt_end[x]++;
    s = x;
  }
  cout << sum_up(1, 0) << endl;
}
