#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void qread(int &x) {
  int neg = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = getchar();
  x *= neg;
}
const int maxn = 4005;
const int maxm = 80;
const int mod = 998244353;
inline int Add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int Sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int Mul(int a, int b) { return 1LL * a * b % mod; }
int n1, n2, k;
int c[maxm][maxm];
class Graph {
 public:
  class Data {
   public:
    int val[maxm];
    Data() { memset(val, 0, sizeof(val)); }
    Data operator+(const Data &o) const {
      Data res;
      for (int(i) = 0; (i) < k + 1; i++) res.val[i] = Add(val[i], o.val[i]);
      return res;
    }
    Data operator-(const Data &o) const {
      Data res;
      for (int(i) = 0; (i) < k + 1; i++) res.val[i] = Sub(val[i], o.val[i]);
      return res;
    }
    Data calc() {
      Data res;
      res.val[0] = 1;
      for (int(i) = 0; (i) < k + 1; i++)
        for (int j = 2; j <= i; j++) {
          res.val[i] = Add(res.val[i], Mul(res.val[j - 2], val[i - j]));
        }
      return res;
    }
  };
  int n, son[maxn];
  vector<int> edge[maxn];
  Data dp[maxn], ans;
  void prework(int x, int p) {
    Data tot;
    for (int(i) = 0; (i) < edge[x].size(); i++) {
      int y = edge[x][i];
      if (y == p) continue;
      prework(y, x);
      tot = tot + dp[y];
    }
    dp[x] = tot.calc();
  }
  void work(int x, int p, Data pval) {
    vector<int> son;
    vector<Data> pre;
    for (int(i) = 0; (i) < edge[x].size(); i++) {
      int y = edge[x][i];
      if (y == p) continue;
      pre.push_back(dp[y]);
      son.push_back(y);
    }
    int sz = son.size();
    for (int(i) = 1; (i) <= sz - 1; i++) pre[i] = pre[i] + pre[i - 1];
    Data cur = (!sz ? Data() : pre[sz - 1]) + pval;
    ans = ans + cur.calc();
    for (int(i) = 0; (i) < son.size(); i++)
      work(son[i], x,
           (pval + pre[sz - 1] - pre[i] + (!i ? Data() : pre[i - 1])).calc());
  }
  void init() {
    for (int(i) = 1; (i) <= n - 1; i++) {
      int u, v;
      qread(u);
      qread(v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    prework(1, 0);
    work(1, 0, Data());
  }
} g1, g2;
int main() {
  qread(n1);
  qread(n2);
  qread(k);
  if (k & 1) {
    printf("%d\n", 0);
    return 0;
  }
  for (int(i) = 0; (i) < k + 1; i++) c[i][0] = 1;
  for (int(i) = 1; (i) <= k; i++)
    for (int(j) = 1; (j) <= k; j++) c[i][j] = Add(c[i - 1][j - 1], c[i - 1][j]);
  g1.n = n1;
  g1.init();
  g2.n = n2;
  g2.init();
  int ans = 0;
  for (int i = 0; i <= k; i += 2) {
    ans = Add(ans, Mul(c[k][i], Mul(g1.ans.val[i], g2.ans.val[k - i])));
  }
  printf("%d\n", ans);
  return 0;
}
