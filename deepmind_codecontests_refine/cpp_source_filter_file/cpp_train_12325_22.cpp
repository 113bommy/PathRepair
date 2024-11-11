#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
template <typename T>
inline T Abs(T x) {
  return (x >= 0) ? x : -x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
inline string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
template <typename T>
inline int bit(T mask, int b) {
  return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0;
}
inline int nextInt() {
  int x;
  if (scanf("%d", &x) != 1) throw;
  return x;
}
inline long long nextInt64() {
  long long x;
  if (scanf("%I64d", &x) != 1) throw;
  return x;
}
inline double nextDouble() {
  double x;
  if (scanf("%lf", &x) != 1) throw;
  return x;
}
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 5100;
const int MAXX = 1011000;
const int MAXS = 10;
int n, k, a[MAXN], size[MAXX];
pair<int, int> e[MAXX][MAXS];
vector<int> l[MAXX];
bool used[MAXN];
bool p[MAXX];
void add(int x, const pair<int, int> &value, bool checkForEqual = true) {
  if (checkForEqual) {
    for (int i = 0; i < (int)(size[x]); i++)
      if (e[x][i] == value) return;
  }
  if (size[x] < MAXS) e[x][size[x]++] = value;
}
bool check(pair<int, int> *a, int n, int v, int k) {
  if (v == n) {
    for (int i = 0; i < (int)(n); i++)
      if (!used[a[i].second] && !used[a[i].first]) return false;
    return true;
  }
  if (used[a[v].second] || used[a[v].first]) return check(a, n, v + 1, k);
  if (k == 0) return false;
  {
    used[a[v].first] = true;
    bool ans = check(a, n, v + 1, k - 1);
    used[a[v].first] = false;
    if (ans) return true;
  }
  {
    used[a[v].second] = true;
    bool ans = check(a, n, v + 1, k - 1);
    used[a[v].second] = false;
    if (ans) return true;
  }
  return false;
}
int main() {
  memset(p, 1, sizeof p);
  for (int i = 2; i < MAXX; i++)
    if (p[i]) {
      for (int j = i; j < MAXX; j += i) {
        p[j] = false;
        l[j].push_back(i);
      }
    }
  n = nextInt();
  k = nextInt();
  for (int i = 0; i < (int)(n); i++) a[i] = nextInt();
  sort(a, a + n);
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(i); j++) add(a[i] - a[j], make_pair(i, j), false);
  int ans = INF;
  for (int i = (int)(MAXX)-1; i >= 0; i--) {
    if (i != 0 && size[i] < MAXS && check(e[i], size[i], 0, k)) ans = i;
    for (int j = 0; j < (int)(l[i].size()); j++) {
      int i1 = i / l[i][j];
      for (int k = 0; k < (int)(size[i]); k++) {
        add(i1, e[i][k]);
        if (size[i1] == MAXS) break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
