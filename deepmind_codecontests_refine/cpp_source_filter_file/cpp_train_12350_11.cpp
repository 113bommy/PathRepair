#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 500005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
struct _ttype {
  int x, p, q;
};
struct UFS {
  int h[2][N], t[N], n, T, p, q;
  deque<_ttype> D;
  void Init(int _n) {
    n = _n;
    for (int i = (1); i <= (n); ++i) h[0][i] = i;
    memset(t, -1, sizeof(t));
    T = 0;
  }
  void Clear() {
    ++T;
    D.clear();
  }
  void Store() {
    while (!D.empty()) h[0][D.front().x] = D.front().q, D.pop_front();
    T++;
  }
  int& G(int x, int k = 1) {
    if (k && t[x] != T) h[1][x] = h[0][x], t[x] = T;
    return h[k][x];
  }
  int Q(int x, int k = 1) { return x == G(x, k) ? x : G(x, k) = Q(G(x, k)); }
  bool U(int x, int y, int k = 1) {
    p = Q(x, k), q = Q(y, k);
    if (p == q) return 0;
    if (k) D.push_back(_ttype{p, G(p, k), q});
    G(p, k) = q;
    T += (k ^ 1);
    return 1;
  }
};
struct ttype {
  int x, y, w;
};
UFS T;
int x, y, w, k, kk, t, n, m;
bool check[N];
vector<pair<int, int> > e[N], q[N];
ttype bian[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); ++i) {
    scanf("%d%d%d", &x, &y, &w);
    bian[i] = ttype{x, y, w};
    e[w].push_back(make_pair(i, i));
  }
  scanf("%d", &k);
  for (int i = (1); i <= (k); ++i) {
    scanf("%d", &kk);
    while (kk--) {
      scanf("%d", &t);
      q[bian[t].w].push_back(make_pair(i, t));
    }
  }
  T.Init(n);
  memset(check, 0, sizeof(check));
  for (int i = (1); i <= (500000); ++i) {
    sort((q[i]).begin(), (q[i]).end());
    for (int j = 0; j < q[i].size(); j++) {
      if (j == 0 || q[i][j].first != q[i][j - 1].first) T.Clear();
      if (!T.U(bian[q[i][j].second].x, bian[q[i][j].second].y))
        check[q[i][j].first] = 1;
    }
    for (__typeof((e[i]).begin()) it = (e[i]).begin(); it != (e[i]).end(); it++)
      T.U(bian[it->first].x, bian[it->first].y, 0);
  }
  for (int i = (1); i <= (k); ++i)
    if (check[i])
      printf("NO\n");
    else
      printf("YES\n");
  return 0;
}
