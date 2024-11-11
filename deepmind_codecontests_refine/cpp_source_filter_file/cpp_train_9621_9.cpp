#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma G++ optimize("O2")
using namespace std;
const int N = 222222;
const int M = 888888;
const int MOD = 1e9 + 7;
const int intINF = 1e9;
const long long llINF = 2e18;
const double pi = acos(-1.0);
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double eps = 1e-10;
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
long long readll() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
unsigned long long readull() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
void predo() {}
struct node {
  long long v, c;
} a[N];
int n;
long long S;
void init() {
  n = read(), S = readll();
  for (int i = (int)1; i <= (int)n; i++) a[i].v = readll(), a[i].c = readll();
}
long long dp[N];
long long calc(long long s, long long i) {
  return max(0ll, (s - dp[i] + a[i].v - 1) / a[i].v);
}
int cmp1(int i, int j, long long V) {
  long long t1 = calc(V, i);
  long long t2 = calc(V, j);
  if (t1 != t2) return t1 > t2;
  return dp[i] + t1 * a[i].v <= dp[j] + t2 * a[j].v;
}
int cmp2(int x, int y, int z) {
  long long x1 = dp[y] - dp[x];
  long long x2 = dp[z] - dp[y];
  long long y1 = a[x].v - a[y].v;
  long long y2 = a[y].v - a[z].v;
  return x1 * y2 < x2 * y1;
}
bool cmp(node a, node b) {
  if (a.c != b.c) return a.c < b.c;
  return a.v < b.v;
}
int q[N];
void solve() {
  sort(a + 1, a + n + 1, cmp);
  long long V = 0;
  long long ans = llINF;
  int t = 1, w = 0;
  for (int i = (int)1; i <= (int)n; i++) {
    if (a[i].v <= V) continue;
    V = a[i].v;
    while (t < w && cmp1(q[t], q[t + 1], a[i].c)) t++;
    if (i > 1) {
      int j = q[t];
      dp[i] = dp[j] - a[i].c - calc(a[i].c, j) * (a[i].v - a[j].v);
    }
    ans = min(ans, calc(S, i));
    while (t < w && cmp2(q[w - 1], q[w], i)) w--;
    q[++w] = i;
  }
  printf("%lld\n", ans);
}
int main() {
  predo();
  int cas = 1;
  while (cas--) {
    init();
    solve();
  }
  return 0;
}
