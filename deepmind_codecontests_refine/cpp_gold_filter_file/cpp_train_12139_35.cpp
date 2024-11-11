#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline char gc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
inline void read(T &x) {
  x = (T)0;
  T f = 1;
  char ssd = gc();
  while (ssd < '0' || ssd > '9') f = ssd == '-' ? -1 : 1, ssd = gc();
  while (ssd >= '0' && ssd <= '9')
    x = (x << 3) + (x << 1) + (ssd - '0'), ssd = gc();
  x = x * f;
}
char OUT[1000000], *S = OUT, *T = OUT + 1000000;
char Num[1000000];
int toP;
inline void out() {
  fwrite(OUT, sizeof(char), S - OUT, stdout);
  S = OUT;
}
inline void pc(char ssd) {
  *S++ = ssd;
  if (S == T) out();
}
template <typename T>
inline void write(T x) {
  if (x == 0) pc('0');
  if (x < 0) x = -x, pc('-');
  toP = 0;
  while (x) Num[++toP] = x % 10 + '0', x /= 10;
  while (toP) pc(Num[toP--]);
}
};  // namespace IO
const int maxn = 1e5 + 10;
namespace President_Tree {
int sum[maxn << 5], ls[maxn << 5], rs[maxn << 5], cnt;
void build(int &node, int l, int r) {
  if (!node) node = ++cnt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(ls[node], l, mid);
  build(rs[node], mid + 1, r);
}
void change(int pre, int &node, int l, int r, int id) {
  if (!node) node = ++cnt;
  sum[node] = sum[pre] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (mid >= id)
    rs[node] = rs[pre], change(ls[pre], ls[node], l, mid, id);
  else
    ls[node] = ls[pre], change(rs[pre], rs[node], mid + 1, r, id);
}
int query(int pre, int node, int l, int r, int k) {
  if (l == r) return sum[node] - sum[pre];
  int mid = (l + r) >> 1;
  if (mid >= k)
    return query(ls[pre], ls[node], l, mid, k);
  else
    return sum[ls[node]] - sum[ls[pre]] +
           query(rs[pre], rs[node], mid + 1, r, k);
}
}  // namespace President_Tree
using namespace President_Tree;
int n, q, K;
int pre[maxn], last[maxn], nxt[maxn], appear[maxn], pos[maxn];
int A[maxn], Pre[maxn];
int root[maxn];
int main() {
  scanf("%d %d", &n, &K);
  for (register int i = 1; i <= n; i += 1) scanf("%d", &A[i]);
  for (register int i = 1; i <= 1e5; i += 1) last[i] = n + 1;
  for (register int i = n; i; i -= 1) {
    nxt[i] = last[A[i]];
    last[A[i]] = i;
  }
  for (register int i = 1; i <= 1e5; i += 1) pos[i] = last[i];
  for (register int i = 1; i <= n; i += 1) {
    appear[A[i]] += 1;
    if (appear[A[i]] > K) {
      Pre[i] = pos[A[i]];
      pos[A[i]] = nxt[pos[A[i]]];
    }
  }
  build(root[0], 0, n);
  for (register int i = 1; i <= n; i += 1)
    change(root[i - 1], root[i], 0, n, Pre[i]);
  int lastans = 0;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    x = (x + lastans) % n + 1;
    y = (y + lastans) % n + 1;
    if (x > y) swap(x, y);
    printf("%d\n", lastans = query(root[x - 1], root[y], 0, n, x - 1));
  }
  return 0;
}
