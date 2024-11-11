#include <bits/stdc++.h>
using namespace std;
int Stv[1 << 8];
inline int read() {
  int f = 1, res = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - 48, ch = getchar();
  return f * res;
}
const int N = 200005;
struct Query {
  int x, y, t, pos;
};
vector<Query> Q[N];
void Insert(int x1, int x2, int y1, int y2, int pos) {
  if (x1 > x2) return;
  if (y1 > y2) return;
  Q[x1 - 1].push_back((Query){y1, y2, -1, pos});
  Q[x2].push_back((Query){y1, y2, 1, pos});
}
int n, m, p[N], v[N];
inline int lowbit(int val) { return val & (-val); }
inline void Add(int pos) {
  if (pos == 0) return;
  for (int k = pos; k <= n; k += lowbit(k)) v[k]++;
}
inline int Ask(int pos) {
  int res = 0;
  for (int k = pos; k > 0; k -= lowbit(k)) res += v[k];
  return res;
}
int cnt;
long long Ans[N], Gil[N * 8];
int main() {
  n = read(), m = read();
  for (int i = 1, _Lim = n; i <= _Lim; i++) p[i] = read();
  for (int i = 1, _Lim = m; i <= _Lim; i++) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    Ans[i] = 1ll * n * (n - 1) / 2;
    Insert(1, x1 - 1, 1, n, ++cnt);
    Insert(x2 + 1, n, 1, n, ++cnt);
    Insert(1, n, 1, y1 - 1, ++cnt);
    Insert(1, n, y2 + 1, n, ++cnt);
    Insert(1, x1 - 1, 1, y1 - 1, ++cnt);
    Insert(1, x1 - 1, y2 + 1, n, ++cnt);
    Insert(x2 + 1, n, 1, y1 - 1, ++cnt);
    Insert(x2 + 1, n, y2 + 1, n, ++cnt);
  }
  for (int i = 1, _Lim = n; i <= _Lim; i++) {
    Add(p[i]);
    for (int j = 0; j < Q[i].size(); j++) {
      int res = Ask(Q[i][j].y) - Ask(Q[i][j].x - 1);
      Gil[Q[i][j].pos] += 1ll * Q[i][j].t * res;
    }
  }
  for (int i = 1, _Lim = m; i <= _Lim; i++)
    for (int t = 0, _Lim = 7; t <= _Lim; t++) {
      long long res = Gil[(i - 1) * 8 + t + 1];
      Ans[i] -= res * (res - 1) / 2 * (t < 4 ? 1 : -1);
    }
  for (int i = 1, _Lim = m; i <= _Lim; i++) printf("%I64d\n", Ans[i]);
}
