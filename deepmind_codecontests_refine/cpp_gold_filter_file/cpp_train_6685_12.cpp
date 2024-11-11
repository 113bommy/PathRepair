#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
const int N = 500010, inf = 2e9;
struct Node {
  int l, r;
  bool operator<(const Node &a) const { return l == a.l ? r < a.r : l < a.l; }
} a[N];
struct Info {
  int x, id, v;
  bool operator<(const Info &b) const { return x < b.x; }
} b[N];
void solve() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) read(a[i].l), read(a[i].r);
  sort(a + 1, a + n + 1);
  int tn = 0, tl = -inf, tr = tl, tot = 0;
  unordered_map<int, int> tmp, sum;
  for (int i = 1; i <= n; i++) {
    if (a[i].r <= tr) continue;
    if (a[i].l > tr) tot++, tl = a[i].l, tmp[tl] = 1;
    chkmax(tr, a[i].r);
  }
  tmp[tl] = 1;
  int m = 0, ans = -inf;
  static int f[N];
  for (int i = 1; i <= n; i++)
    b[++m] = (Info){a[i].l, i, 1}, b[++m] = (Info){a[i].r, i, -1}, f[i] = 0;
  sort(b + 1, b + m + 1);
  set<int> s;
  for (int i = 1; i <= m; i++) {
    int j = i - 1;
    vector<int> v, del;
    v.clear(), del.clear();
    while (j < m && b[j + 1].x == b[i].x)
      if (b[++j].v == 1)
        v.push_back(b[j].id);
      else
        del.push_back(b[j].id);
    if (s.size() == 1 && !v.empty()) f[*s.begin()]++;
    for (int x : v) s.insert(x);
    for (int x : del) s.erase(x);
    i = j;
  }
  for (int i = 1; i <= n; i++)
    if (tmp[a[i].l]) sum[a[i].l]++;
  for (int i = 1; i <= n; i++) chkmax(ans, f[i] - (sum[a[i].l] == 1));
  cout << ans + tot << '\n';
}
int main() {
  int T;
  read(T);
  while (T--) solve();
  return 0;
}
