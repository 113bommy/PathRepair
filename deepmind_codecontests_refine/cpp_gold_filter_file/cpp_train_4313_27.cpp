#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
struct node {
  int w, p;
  node() {}
  node(int w, int p) : w(w), p(p) {}
} p[N], now;
int n, x, ls, nx, ny, rs, y;
bool tag;
double ans, s1, s2;
int a[N], nxt[N], pre[N], p1[N], p2[N];
bool cmp(node a, node b) { return a.w < b.w; }
void del(int k) {
  nxt[pre[k]] = nxt[k];
  pre[nxt[k]] = pre[k];
}
int read() {
  int num = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    num = num * 10 + c - '0';
    c = getchar();
  }
  return num;
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) a[i] = read();
  for (i = 1; i <= n; i++) p[i] = node(a[i], i);
  sort(p + 1, p + 1 + n, cmp);
  for (i = 1; i <= n; i++) nxt[i] = i + 1, pre[i] = i - 1;
  for (i = 1; i <= n; i++) {
    now = p[i];
    ls = rs = 0;
    x = y = now.p;
    while (x && ls <= 30) p1[++ls] = x - pre[x], x = pre[x];
    while (y <= n && rs <= 30) p2[++rs] = nxt[y] - y, y = nxt[y];
    s1 = s2 = 0;
    for (j = 1; j <= ls; j++) s1 += (double)p1[j] / (1ll << j);
    for (j = 1; j <= rs; j++) s2 += (double)p2[j] / (1ll << j);
    ans += (double)now.w * s1 * s2 * 2.0;
    del(now.p);
  }
  printf("%.6f\n", ans / ((double)n * n));
  return 0;
}
