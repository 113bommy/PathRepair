#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int BLOCK_SIZE;
void Dbg() { puts(""); }
template <typename T, typename... Args>
void Dbg(T x, Args... args) {
  cout << x << ' ';
  Dbg(args...);
}
template <typename T>
inline void readInt(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
template <typename T, typename... Args>
inline void readInt(T &x, Args &...args) {
  readInt(x), readInt(args...);
}
template <typename T>
inline void readChar(T &x) {
  char c = getchar();
  while (c == '\n' || c == ' ') c = getchar();
  x = c;
}
struct Query {
  int L, R, id, tm, bl, br;
  Query() {}
  Query(int _L, int _R, int _id, int _tm) : L(_L), R(_R), id(_id), tm(_tm) {
    bl = L / BLOCK_SIZE;
    br = R / BLOCK_SIZE;
  }
  bool operator<(const Query &rhs) const {
    return bl == rhs.bl ? (br == rhs.br ? tm < rhs.tm : br < rhs.br)
                        : bl < rhs.bl;
  }
} Q[maxN];
struct Change {
  int pos, now, pre;
} C[maxN];
int n, q, sz, tmp, Cidx, Qidx;
int qs[maxN], num[maxN], cnt[maxN], ans[maxN], now[maxN];
map<int, int> xs;
inline int getId(int x) {
  if (!xs.count(x)) xs[x] = ++sz;
  return xs[x];
}
inline void revise(int x, int d) {
  if (num[x] > 0) cnt[num[x]]--;
  num[x] += d;
  if (num[x] > 0) cnt[num[x]]++;
}
inline void update(int x, int d, int L, int R) {
  if (L <= x && x <= R) revise(qs[x], -1), revise(d, 1);
  qs[x] = d;
}
int main() {
  scanf("%d%d", &n, &q), BLOCK_SIZE = pow(n, 0.666666);
  for (int i = 1; i <= n; i++)
    scanf("%d", qs + i), now[i] = qs[i] = getId(qs[i]);
  for (int i = 1, op, a, b; i <= q; i++) {
    scanf("%d%d%d", &op, &a, &b);
    if (op == 1)
      Q[++Qidx] = Query(a, b, Qidx, Cidx);
    else
      b = getId(b), C[++Cidx] = {a, b, now[a]}, now[a] = b;
  }
  sort(Q + 1, Q + 1 + Qidx);
  for (int i = 1, L = 1, R = 0, T = 0; i <= Qidx; i++) {
    Query &q = Q[i];
    int x = 1;
    while (T < q.tm) ++T, update(C[T].pos, C[T].now, L, R);
    while (T > q.tm) update(C[T].pos, C[T].pre, L, R), T--;
    while (L < q.L) revise(qs[L++], -1);
    while (L > q.L) revise(qs[--L], 1);
    while (R < q.R) revise(qs[++R], 1);
    while (R > q.R) revise(qs[R--], -1);
    while (cnt[x]) x++;
    ans[q.id] = x;
  }
  for (int i = 1; i <= Qidx; i++) printf("%d\n", ans[i]);
}
