#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
int n, m;
struct BIT {
  ll c[N][N];
  inline int lowbit(int x) { return x & -x; }
  void modify(int x, int y, ll v) {
    while (x <= n) {
      for (int i = y; i <= m; i += lowbit(i)) c[x][i] ^= v;
      x += lowbit(x);
    }
  }
  ll query(int x, int y) {
    ll ret = 0;
    while (x) {
      for (int i = y; i > 0; i -= lowbit(i)) ret ^= c[x][i];
      x -= lowbit(x);
    }
    return ret;
  }
} t[2][2];
inline void modify(int x, int y, ll v) { t[x & 1][y & 1].modify(x, y, v); }
inline ll query(int x, int y) { return t[x & 1][y & 1].query(x, y); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  while (m--) {
    int op, x0, y0, x1, y1;
    ll v;
    cin >> op;
    if (op == 1) {
      cin >> x0 >> y0 >> x1 >> y1;
      cout << (query(x1, y1) ^ query(x1, y0 - 1) ^ query(x0 - 1, y1) ^
               query(x0 - 1, y0 - 1))
           << endl;
    } else {
      cin >> x0 >> y0 >> x1 >> y1 >> v;
      modify(x0, y0, v);
      modify(x1 + 1, y0, v);
      modify(x0, y1 + 1, v);
      modify(x1 + 1, y1 + 1, v);
    }
  }
  return 0;
}
