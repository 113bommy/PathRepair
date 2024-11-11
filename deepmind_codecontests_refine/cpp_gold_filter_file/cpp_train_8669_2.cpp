#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, size = 1 << 20, mod = 998244353, inf = 2e9;
template <class o>
void qr(o& x) {
  char c = getchar();
  x = 0;
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
void cmax(int& x, int y) { x = x - y >> 31 ? y : x; }
int n, a[N], R[N];
class dsu {
 public:
  vector<int> fa;
  int n;
  dsu(int _n) : n(_n) {
    fa.resize(n);
    iota(fa.begin(), fa.end(), 0);
  }
  int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x ^ y) {
      fa[x] = y;
      return 1;
    }
    return 0;
  }
};
int bound[N];
int solve() {
  qr(n);
  for (int i = 1; i <= n; i++) qr(a[i]);
  int mx = a[n];
  for (int i = 1; i <= mx; i++) bound[i] = 0;
  for (int i = 1; i <= n; i++) bound[a[i]] = i;
  for (int i = 1; i <= mx; i++) cmax(bound[i], bound[i - 1]);
  a[0] = mx + 1;
  for (int i = 0; i <= n - 1; i++) R[i] = n;
  vector<vector<int> > who(1, vector<int>(n + 1, -1));
  vector<dsu> d(1, dsu(n + 2));
  vector<bool> seen;
  for (int i = n; i >= 1; i--) {
    int j = 0, start = 1, finish;
    while (start < i) {
      if (j == ((int)who.size())) {
        who.emplace_back(n + 1, -1);
        d.push_back(dsu(n + 2));
      }
      finish = i - 1;
      int tmp = who[j][i];
      if (tmp != -1) {
        int x = 2 * a[i] - a[tmp];
        finish = (x <= 0 ? 0 : bound[x]);
      }
      if (start <= finish) {
        int pos = d[j].get(start);
        while (pos <= finish) {
          who[j][pos] = i;
          d[j].unite(pos, pos + 1);
          pos = d[j].get(++pos);
        }
        start = finish + 1;
      }
      ++j;
    }
    int g = 0;
    while (g < ((int)who.size()) && who[g][i] != -1) g++;
    if (g >= ((int)seen.size())) seen.resize(g + 1);
    seen[g] = 1;
  }
  int g = 0;
  while (g < ((int)seen.size()) && seen[g]) g++;
  return g;
}
int main() {
  int T = 1, ans = 0;
  qr(T);
  while (T--) ans ^= solve();
  puts(ans ? "YES" : "NO");
  return 0;
}
