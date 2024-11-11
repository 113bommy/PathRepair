#include <bits/stdc++.h>
const long long INF = 1e18;
long long n, m, l, r, ans[1000005][4];
long long read() {
  long long ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans;
}
void Write(long long x) {
  if (x < 10)
    putchar(x + '0');
  else
    Write(x / 10), putchar(x % 10 + '0');
}
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x < y ? x : y; }
namespace Segment_Tree {
std::pair<long long, long long> Tree[1000005];
long long n;
std::pair<long long, long long> merge(std::pair<long long, long long> X,
                                      std::pair<long long, long long> Y) {
  return X.first < Y.first ? X : Y;
}
void pushup(long long rt) {
  Tree[rt] = merge(Tree[rt << 1], Tree[rt << 1 | 1]);
}
void build(long long L, long long R, long long rt) {
  if (L == R)
    Tree[rt] = std::make_pair(INF, L);
  else
    build(L, (L + R) / 2, rt << 1), build((L + R) / 2 + 1, R, rt << 1 | 1),
        pushup(rt);
}
void init(long long nn) { build(1, n = nn, 1); }
std::pair<long long, long long> query(long long L, long long R, long long l,
                                      long long r, long long rt) {
  if (l <= L && R <= r) return Tree[rt];
  int mid = (L + R) / 2;
  if (mid < l) return query(mid + 1, R, l, r, rt << 1 | 1);
  if (mid >= r) return query(L, mid, l, r, rt << 1);
  return merge(query(L, mid, l, r, rt << 1),
               query(mid + 1, R, l, r, rt << 1 | 1));
}
std::pair<long long, long long> query(long long l, long long r) {
  return query(1, n, l, r, 1);
}
void modify(long long L, long long R, long long rt,
            std::pair<long long, long long> X) {
  if (L == R)
    Tree[rt] = X;
  else {
    if ((L + R) / 2 >= X.second)
      modify(L, (L + R) / 2, rt << 1, X);
    else
      modify((L + R) / 2 + 1, R, rt << 1 | 1, X);
    pushup(rt);
  }
}
void modify(long long x, long long y) {
  return modify(1, n, 1, std::make_pair(y, x));
}
}  // namespace Segment_Tree
int main() {
  n = read(), m = read(), l = read(), r = read();
  Segment_Tree::init(m);
  for (long long a = m; a; a--) {
    for (long long X1 = a; X1 <= n; X1 += a) {
      long long minn = max(1, (l + X1 - 1) / X1), maxn = min(m, r / X1);
      if (minn <= maxn) {
        std::pair<long long, long long> tmp = Segment_Tree::query(minn, maxn);
        if (tmp.first != INF && X1 / a * tmp.first <= n)
          ans[X1][0] = X1, ans[X1][1] = tmp.second,
          ans[X1][2] = X1 * tmp.first / a,
          ans[X1][3] = tmp.second * a / tmp.first;
      }
    }
    for (long long X1 = a; X1 <= m; X1 += a) Segment_Tree::modify(X1, a);
  }
  for (long long i = 1; i <= n; i++)
    if (ans[i][0])
      Write(ans[i][0]), putchar(' '), Write(ans[i][1]), putchar(' '),
          Write(ans[i][2]), putchar(' '), Write(ans[i][3]), putchar('\n');
    else
      putchar('-'), putchar('1'), putchar('\n');
  return 0;
}
