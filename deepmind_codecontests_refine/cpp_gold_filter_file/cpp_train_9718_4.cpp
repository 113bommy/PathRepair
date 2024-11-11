#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int MOD = 1000000007;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void upd(T &a, T b) {
  (a += b) %= MOD;
}
template <class T>
void mul(T &a, T b) {
  a = (long long)a * b % MOD;
}
int n, m, top, badedge, sumbad;
int dep[N], col[N], head[N];
int parb[N];
pair<int, int> b[N];
struct Edge {
  int to, nxt, id;
} e[N << 1];
void add(int a, int b, int id) {
  e[++top] = (Edge){b, head[a], id};
  head[a] = top;
}
void dfs(int i, int fat, int c, int id) {
  col[i] = c;
  dep[i] = dep[fat] + 1;
  parb[i] = id;
  int backbad = 0, backok = 0;
  for (int idd = head[i]; idd; idd = e[idd].nxt) {
    int j = e[idd].to;
    if (j == fat) continue;
    if (col[j] == -1) {
      dfs(j, i, c ^ 1, e[idd].id);
      backbad += b[j].first;
      backok += b[j].second;
    } else {
      if (dep[j] > dep[i]) {
        if (col[i] == col[j])
          backbad--;
        else
          backok--;
      } else {
        if (col[i] == col[j]) {
          backbad++;
          badedge = e[idd].id;
          sumbad++;
        } else {
          backok++;
        }
      }
    }
  }
  b[i] = make_pair(backbad, backok);
}
signed main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b, i);
    add(b, a, i);
  }
  memset(col, -1, sizeof(col));
  for (int i = (1); i <= (n); i++)
    if (col[i] == -1) dfs(i, 0, 0, 0);
  if (sumbad == 0) {
    printf("%d\n", m);
    for (int i = (1); i <= (m); i++) cout << i << " ";
    cout << endl;
  } else {
    set<int> res;
    if (sumbad == 1) res.insert(badedge);
    for (int i = (1); i <= (n); i++) {
      if (!parb[i]) continue;
      if (b[i].first == sumbad && b[i].second == 0) res.insert(parb[i]);
    }
    vector<int> ans(res.begin(), res.end());
    printf("%d\n", ((int)ans.size()));
    for (int i = (0); i <= (((int)ans.size()) - 1); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
