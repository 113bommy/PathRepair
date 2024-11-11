#include <bits/stdc++.h>
const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
int n, q;
int a[N];
bool dbg;
struct tree {
  int t[N * 4 + 10], fl[N * 4 + 10], u[N * 4 + 10];
  tree() { memset(u, -1, sizeof(u)); }
  void push(int v) {
    if (u[v] != -1) {
      t[v << 1] = t[v << 1 | 1] = u[v];
      fl[v << 1] = fl[v << 1 | 1] = 0;
      u[v << 1] = u[v << 1 | 1] = u[v];
      u[v] = -1;
    }
    if (fl[v]) {
      t[v << 1] ^= 1;
      t[v << 1 | 1] ^= 1;
      fl[v << 1] ^= 1;
      fl[v << 1 | 1] ^= 1;
      fl[v] = 0;
    }
  }
  void upd(int l, int r, int tp, int x, int v = 1, int tl = 0, int tr = N) {
    if (tl > r || tr < l || l > r) return;
    if (l <= tl && tr <= r) {
      if (tp == 1) {
        t[v] ^= 1;
        fl[v] ^= 1;
      } else {
        t[v] = u[v] = x;
        fl[v] = 0;
      }
      return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    upd(l, r, tp, x, v << 1, tl, tm);
    upd(l, r, tp, x, v << 1 | 1, tm + 1, tr);
  }
  int get(int p, int v = 1, int tl = 0, int tr = N) {
    if (tl == tr) return t[v];
    int tm = (tl + tr) >> 1;
    push(v);
    if (p <= tm) return get(p, v << 1, tl, tm);
    return get(p, v << 1 | 1, tm + 1, tr);
  }
} t[2];
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = (1); i <= (n); i++) {
    cin >> a[i];
    if (a[i] > 0) t[1].upd(a[i], a[i], 2, 1);
    if (a[i] < 0) t[0].upd(-a[i], -a[i], 2, 0);
  }
  for (int i = (1); i <= (q); i++) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '>') {
      if (x > 0) {
        t[0].upd(abs(x) + 1, N, 2, 0);
        t[1].upd(abs(x) + 1, N, 2, 0);
      }
      if (x < 0) {
        t[0].upd(-x, N, 2, 0);
        t[1].upd(-x, N, 2, 0);
        t[0].upd(1, abs(x) - 1, 1, -1);
        t[1].upd(1, abs(x) - 1, 1, -1);
      }
    } else {
      if (x > 0) {
        t[0].upd(x, N, 2, 1);
        t[1].upd(x, N, 2, 1);
        t[0].upd(1, x - 1, 1, -1);
        t[1].upd(1, x - 1, 1, -1);
      }
      if (x < 0) {
        t[0].upd(abs(x) + 1, N, 2, 1);
        t[1].upd(abs(x) + 1, N, 2, 1);
      }
    }
  }
  for (int i = (1); i <= (n); i++) {
    if (a[i] > 0) {
      if (!t[1].get(a[i])) a[i] = -a[i];
    } else {
      if (t[0].get(-a[i])) a[i] = -a[i];
    }
    cout << a[i] << ' ';
  }
  exit(0);
}
