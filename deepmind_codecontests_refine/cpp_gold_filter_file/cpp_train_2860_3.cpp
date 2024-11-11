#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const long long N = 100005;
long long n, m, k, p, h[N], a[N], cnt[N];
long long t[N];
struct Node {
  long long id;
  long long v;
  Node(long long iid = 0, long long vv = 0) { id = iid, v = vv; }
  bool operator<(Node w) const { return v > w.v; }
} tmp;
priority_queue<Node> H;
long long nowh[N], nowv[N], tim[N];
inline long long calc(long long v, long long a) {
  if (v < 0) return 0;
  return v / a + 1;
}
inline long long calc2(long long v, long long a) {
  if (v >= 0) return 0;
  v = -v;
  return v % a == 0 ? v / a : v / a + 1;
}
inline bool check(long long v) {
  while (!H.empty()) H.pop();
  long long nowt = 0, i;
  for (i = 1; i <= n; ++i) {
    nowh[i] = v;
    tim[i] = 0;
    nowv[i] = calc(nowh[i], a[i]);
    H.push(Node(i, tim[i] + nowv[i]));
  }
  long long x;
  long long vv;
  for (i = 1; i <= m; ++i) {
    while (H.size()) {
      tmp = H.top();
      x = tmp.id;
      if (tmp.v > i) break;
      H.pop();
      nowh[x] -= nowv[x] * a[x], tim[x] += nowv[x];
      vv = calc2(nowh[x], p);
      nowt -= vv;
      if (nowt < 0) return 0;
      nowh[x] += vv * p;
      while (nowh[x] < 0) nowh[x] += p, --nowt;
      if (nowt < 0) return 0;
      nowv[x] = calc(nowh[i], a[x]);
      H.push(Node(x, tim[x] + nowv[x]));
    }
    nowt += k;
  }
  for (i = 1; i <= n; ++i) {
    nowh[i] -= (m - tim[i]) * a[i];
    nowh[i] -= h[i];
    nowt -= calc2(nowh[i], p);
    if (nowt < 0) return 0;
  }
  return 1;
}
signed main() {
  long long i, L = 0, R = 1000000000ll * 5050ll, Mid, Ans = R;
  read(n), read(m), read(k), read(p);
  for (i = 1; i <= n; ++i) read(h[i]), read(a[i]), L = max(L, a[i]);
  while (L <= R) {
    Mid = L + R >> 1;
    if (check(Mid))
      Ans = Mid, R = Mid - 1;
    else
      L = Mid + 1;
  }
  cout << Ans << '\n';
  return 0;
}
