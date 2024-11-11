#include <bits/stdc++.h>
using namespace std;
const int maxn = 300030;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 0;
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
struct ques {
  int l, r, id;
  bool operator<(const ques &q) const { return r < q.r; }
} q[maxn];
struct seg {
  int x, y, d;
  bool operator<(const seg &s) const {
    if (x != s.x) return x < s.x;
    if (y != s.y) return y < s.y;
    return d < s.d;
  }
};
int n, Q, ans[maxn], tmpx[maxn], tmpy[maxn], bit[maxn];
vector<seg> v[maxn];
map<seg, int> at;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void update(int p, int v) {
  for (int i = p; i <= n; i += i & -i) bit[i] += v;
}
int query(int p) {
  int s = 0;
  for (int i = p; i; i -= i & -i) s += bit[i];
  return s;
}
int query(int l, int r) { return query(r) - query(l - 1); }
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) {
    int k = read();
    for (int j = (1); j <= (k); j++) tmpx[j] = read(), tmpy[j] = read();
    for (int j = (1); j <= (k); j++) {
      int dx = tmpx[j] - tmpx[j == 1 ? k : j - 1],
          dy = tmpy[j] - tmpy[j == 1 ? k : j - 1], tp = 0;
      if (dx < 0 || dx == 0 && dy < 0) tp = 1;
      int g = gcd(dx, dy);
      dx /= g;
      dy /= g;
      if (dx < 0 || dx == 0 && dy < 0) dx = -dx, dy = -dy;
      v[i].push_back((seg){dx, dy, tp});
    }
  }
  Q = read();
  for (int i = (1); i <= (Q); i++) {
    int l = read(), r = read();
    q[i] = (ques){l, r, i};
  }
  sort(q + 1, q + Q + 1);
  int cur = 1;
  for (int i = (1); i <= (Q); i++) {
    while (cur <= q[i].r) {
      for (int j = (0); j <= ((int)v[cur].size() - 1); j++) {
        if (at[v[cur][j]]) update(at[v[cur][j]], -1);
        update(at[v[cur][j]] = cur, 1);
      }
      cur++;
    }
    ans[q[i].id] = query(q[i].l, q[i].r);
  }
  for (int i = (1); i <= (Q); i++) printf("%d\n", ans[i]);
}
