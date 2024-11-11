#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 17;
const int MX = (int)1e6 + 17;
const int MOD = (int)1e9 + 7;
const long long oo = LLONG_MAX;
const int INF = INT_MAX;
const long double Pi = 3.14159265358979323846264338327950288419716939937510;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};
inline long long IN() {
  long long x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void OUT(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    OUT(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
void IOI2017() {
  freopen(
      "partition"
      ".in",
      "r", stdin);
  freopen(
      "partition"
      ".out",
      "w", stdout);
}
int n;
int ans[2 * N];
vector<int> t[8 * N];
struct node {
  int l, r, id;
} a[2 * N];
bool cmp(node a, node b) {
  if (a.l != b.l)
    return a.l < b.l;
  else
    return a.r < b.r;
}
inline void build(int v = 1, int tl = 1, int tr = n) {
  if (tl == tr)
    t[v].push_back(a[tl].r);
  else {
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build((v << 1) + 1, tm + 1, tr);
    merge(t[v << 1].begin(), t[v << 1].end(), t[(v << 1) + 1].begin(),
          t[(v << 1) + 1].end(), back_inserter(t[v]));
  }
}
inline int get(int l, int r, int val, int v = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return 0;
  if (l <= tl && tr <= r)
    return lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
  int tm = (tl + tr) >> 1;
  return get(l, r, val, v << 1, tl, tm) +
         get(l, r, val, (v << 1) + 1, tm + 1, tr);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  build();
  for (int i = 1, cur; i <= n; i++) {
    cur = get(i, n, a[i].r);
    ans[a[i].id] = cur;
  }
  for (int i = 1; i <= n; i++) printf("%d\n", &ans[i]);
  return 0;
}
