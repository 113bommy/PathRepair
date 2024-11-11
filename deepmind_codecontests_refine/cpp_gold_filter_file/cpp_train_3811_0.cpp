#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const int N = 1e5 + 7, inf = 1e9 + 7, mod = 1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int get_int() {
  char x = getchar();
  bool mns = 0;
  while (!isdigit(x)) mns |= x == '-', x = getchar();
  int res = 0;
  while (isdigit(x)) res = res * 10 + x - '0', x = getchar();
  if (mns) res = -res;
  return res;
}
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
int mult(int x, int y) { return x * 1ll * y % mod; }
int sum(int x, int y) {
  add(x, y);
  return x;
}
int n;
char second[N];
int type(char x) {
  if (x == 'A') return 0;
  if (x == 'T') return 1;
  if (x == 'G') return 2;
  return 3;
}
struct fenwick {
  int first[4][N];
  void upd(int t, int p, int x) {
    for (; p < N; p |= p + 1) first[t][p] += x;
  }
  int pref(int t, int p) {
    int res = 0;
    for (; p >= 0; p = (p & (p + 1)) - 1) res += first[t][p];
    return res;
  }
  int get(int t, int l, int r) { return pref(t, r) - pref(t, l - 1); }
} t[10][10];
void solve() {
  cin >> second + 1;
  n = strlen(second + 1);
  for (int i = 0; i <= 9; i++) {
    int m = i + 1;
    for (int j = 1; j <= n; j++) {
      t[i][j % m].upd(type(second[j]), j, 1);
    }
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int p;
      char x;
      cin >> p >> x;
      if (second[p] != x) {
        for (int j = 0; j <= 9; j++) {
          int m = j + 1;
          t[j][p % m].upd(type(second[p]), p, -1);
          t[j][p % m].upd(type(x), p, 1);
        }
        second[p] = x;
      }
    } else {
      int l, r;
      string q;
      cin >> l >> r >> q;
      int len = (int)q.size(), res = 0;
      for (int j = l, ptr = 0; j <= min(r, l + len - 1); j++, ptr++) {
        res += t[len - 1][j % len].get(type(q[ptr]), l, r);
      }
      cout << res << '\n';
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  exit(0);
}
