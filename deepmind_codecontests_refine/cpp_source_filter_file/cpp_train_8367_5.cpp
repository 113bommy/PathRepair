#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T &a, T &b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T &a, T &b) {
  return a > b ? a : b;
}
template <class T>
void read(T &x) {
  char ch;
  while ((ch = getchar()) && !isdigit(ch))
    ;
  x = ch - '0';
  while ((ch = getchar()) && isdigit(ch)) x = x * 10 + ch - '0';
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
long long Pow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 120000;
struct lj {
  int x, y;
} P[N];
int n, t[6000000], L[6000000], R[6000000], cnt, root[N];
void add(int &p, int q, int l, int u = 1, int v = n * 2) {
  if (!p) t[p = ++cnt] = t[q];
  t[p]++;
  if (u == v) return;
  int mid = u + v >> 1;
  if (l <= mid)
    R[p] = R[q], add(L[p], L[q], l, u, mid);
  else
    L[p] = L[q], add(R[p], R[q], l, mid + 1, v);
}
int ask(int p, int q, int l, int r, int u = 1, int v = n * 2) {
  if (l > r) return 0;
  if (l == u && r == v) return t[q] - t[p];
  int mid = u + v >> 1;
  if (r <= mid)
    return ask(L[p], L[q], l, r, u, mid);
  else if (l > mid)
    return ask(R[p], R[q], l, r, mid + 1, v);
  else
    return ask(L[p], L[q], l, mid, u, mid) +
           ask(R[p], R[q], mid + 1, r, mid + 1, v);
}
inline int cmp(const lj &a, const lj &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
long long Type1() {
  int x, y, c1, c2;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    x = P[i].x, y = P[i].y;
    c1 = ask(root[x], root[y], x + 1, y - 1);
    c2 = ask(root[y], root[n << 1], y + 1, (n << 1));
    c2 += ask(root[0], root[x], 1, x - 1) +
          ask(root[0], root[x], y + 1, (n << 1));
    ans += (long long)c1 * c2;
  }
  return ans;
}
long long Type2() {
  int x, y, c1, c2;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    x = P[i].x, y = P[i].y;
    c1 = ask(root[x], root[y], x + 1, y - 1);
    c1 += ask(root[y], root[n << 1], y + 1, (n << 1));
    c1 += ask(root[0], root[x], 1, x - 1) +
          ask(root[0], root[x], y + 1, (n << 1));
    c2 = ask(root[x], root[y], y + 1, (n << 1)) +
         ask(root[0], root[x], x + 1, y - 1);
    ans += (long long)c1 * c2;
  }
  return ans / 2LL;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &P[i].x, &P[i].y);
    if (P[i].x > P[i].y) swap(P[i].x, P[i].y);
  }
  sort(P + 1, P + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (P[i].x != P[i - 1].x)
      for (int j = P[i - 1].x + 1; j <= P[i].x - 1; j++) root[j] = root[j - 1];
    add(root[P[i].x], root[P[i - 1].x], P[i].y);
  }
  if (P[n].x != (n << 1))
    for (int j = P[n].x + 1; j <= n << 1; j++) root[j] = root[j - 1];
  long long ans = (long long)n * (n - 1) * (n - 2) / 6LL;
  ans -= Type1();
  ans -= Type2();
  printf("%lld\n", ans);
}
