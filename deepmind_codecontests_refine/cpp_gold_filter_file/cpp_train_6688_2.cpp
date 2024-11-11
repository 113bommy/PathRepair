#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  while (b != 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a < 0 ? -a : a;
}
inline long long lowbit(long long x) { return x & (-x); }
int head[2000010], Edge_Num;
struct Edge {
  int to, next;
  long long w;
} e[4000010];
inline void ade(int x, int y, long long w) {
  e[++Edge_Num] = {y, head[x], w};
  head[x] = Edge_Num;
}
inline void G_init(int n) {
  memset(head, 0, sizeof(int) * (n + 100));
  Edge_Num = 0;
}
int dir[8][2] = {{-1, 0}, {0, -1}, {-1, -1}, {1, -1},
                 {1, 0},  {0, 1},  {1, 1},   {-1, 1}};
const long double PI = 3.14159265358979323846;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline void pt(long long x) { printf("%lld ", x); }
inline void pt(int x) { printf("%d ", x); }
inline void ptn(int x) { printf("%d\n", x); }
inline void ptn(long long x) { printf("%lld\n", x); }
inline long long rd() {
  long long x = 0;
  bool f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? x : -x;
}
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const int M = 1e6 + 10;
const int N = 2e5 + 10;
int a[N], n, k, b[N];
bool check() {
  n = rd(), k = rd();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = rd();
    if (a[i] == k) ++cnt;
  }
  if (!cnt) return 0;
  if (cnt == n) return 1;
  for (int i = 1; i + 1 <= n; i++) {
    int m = 0;
    for (int j = i; j <= min(n, i + 2); j++) {
      b[++m] = a[j];
    }
    sort(b + 1, b + 1 + m);
    if (b[(m + 1) / 2] >= k) return 1;
  }
  return 0;
}
void solve() { puts(check() ? "yes" : "no"); }
int main() {
  int T = 1;
  T = rd();
  while (T--) solve();
}
