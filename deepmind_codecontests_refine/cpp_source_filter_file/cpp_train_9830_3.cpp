#include <bits/stdc++.h>
using namespace std;
using L = long long;
using PII = pair<int, int>;
using PLL = pair<L, L>;
using VI = vector<int>;
using VL = vector<L>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using VPII = vector<PII>;
using VPLL = vector<PLL>;
using UMII = unordered_map<int, int>;
using UMLL = unordered_map<L, L>;
using USI = unordered_set<int>;
using USL = unordered_set<L>;
void SC(int &i) { scanf("%d", &i); }
void SC(int &i, int &j) { scanf("%d %d", &i, &j); }
void SC(int &i, int &j, int &k) { scanf("%d %d %d", &i, &j, &k); }
void SC(L &i) { scanf("%lld", &i); }
void SC(L &i, L &j) { scanf("%lld %lld", &i, &j); }
void SC(L &i, L &j, L &k) { scanf("%lld %lld %lld", &i, &j, &k); }
void print(VL arr, const string sep = " ", const string end = "\n") {
  for (L i = 0; i < ((int)arr.size()); ++i)
    printf("%lld%s", arr[i], sep.c_str());
  printf("%s", end.c_str());
}
void print(VI arr, const string sep = " ", const string end = "\n") {
  for (L i = 0; i < ((int)arr.size()); ++i) printf("%d%s", arr[i], sep.c_str());
  printf("%s", end.c_str());
}
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = (1 << 4);
struct node {
  int open, close, ans;
  node(int o = 0, int c = 0, int a = 0) { open = o, close = c, ans = a; }
};
node t[2 * N + 1];
int n;
node merge(node &a, node &b) {
  int o, c, ans;
  ans = min(a.open, b.close);
  o = a.open + b.open - ans;
  c = a.close + b.close - ans;
  ans *= 2;
  ans += (a.ans + b.ans);
  node nnode = node(o, c, ans);
  return nnode;
}
void build(string &s) {
  for (L i = 0; i < n; ++i)
    t[i + N] = (s[i] == '(' ? node(1, 0, 0) : node(0, 1, 0));
  for (int i = N - 1; i > 0; --i) t[i] = merge(t[i << 1], t[i << 1 | 1]);
}
int query(int l, int r) {
  node lans, rans;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lans = merge(lans, t[l++]);
    if (r & 1) rans = merge(t[--r], rans);
  }
  return merge(lans, rans).ans;
}
int main() {
  string s;
  cin >> s;
  n = ((int)s.size());
  build(s);
  int m;
  SC(m);
  for (L mi = 0; mi < m; ++mi) {
    int li, ri;
    SC(li, ri);
    print(VI{query(li - 1, ri)});
  }
  return 0;
}
