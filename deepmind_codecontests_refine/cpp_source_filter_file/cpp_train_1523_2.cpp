#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int INF = 1 << 20;
const int MOD = 1000000007;
bool vis[maxn];
int x[maxn], y[maxn];
int a[maxn], b[maxn];
int n, ans1, ans2;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    a[i] = x[i] + y[i];
    b[i] = x[i] - y[i];
  }
}
void checkmin(int &x, int y) {
  if (y < x) x = y;
}
void checkmax(int &x, int y) {
  if (y > x) x = y;
}
int Fmax(int x, int y) { return x > y ? x : y; }
int Fmin(int x, int y) { return x < y ? x : y; }
int Fabs(int x) { return x < 0 ? -x : x; }
void dfs(int t) {
  vis[t] = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i] && Fabs(x[t] - x[i]) + Fabs(y[t] - y[i]) > ans1) dfs(i);
}
void work() {
  int a0 = INF, a1 = -INF, b0 = INF, b1 = -INF;
  for (int i = 1; i <= n; i++) {
    checkmin(a0, a[i]);
    checkmax(a1, a[i]);
    checkmin(b0, b[i]);
    checkmax(b1, b[i]);
  }
  int s0 = 0, s1 = 0;
  for (int i = 1; i <= n; i++) {
    checkmax(s0, Fmin(Fmax(a[i] - a0, b[i] - b0), Fmax(a1 - a[i], b1 - b[i])));
    checkmax(s1, Fmin(Fmax(a[i] - b0, b1 - b[i]), Fmax(a1 - a[i], b[i] - b0)));
  }
  ans1 = Fmin(s0, s1);
  ans2 = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i), ans2 = (ans2 << 1) % MOD;
}
void print() { printf("%d\n%d\n", ans1, ans2); }
int main() {
  init();
  work();
  print();
  return 0;
}
