#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
  int w, pos, opt;
};
node x[N * 2];
int tot;
int s[N], d[N], e[N], k[N];
int c[N * 4];
int n;
int g[N];
bool check(int i, int j) {
  if (d[i] > 0 && d[j] > 0) {
    if (s[i] > s[j]) return true;
  }
  if (d[i] < 0 && d[j] < 0) {
    if (s[i] < s[j]) return true;
  }
  return false;
}
bool cmp(node a, node b) { return a.w < b.w; }
int lowbit(int xx) { return xx & (-xx); }
void add(int xx, int w) {
  for (; xx <= tot; xx += lowbit(xx)) c[xx] += w;
}
int sum(int xx) {
  int ret = 0;
  for (; xx; xx -= lowbit(xx)) ret += c[xx];
  return ret;
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &s[i], &d[i]);
    e[i] = s[i] + d[i];
    s[i] = s[i] * N - i;
    e[i] = e[i] * N - i;
    k[i] = i;
    tot++;
    x[tot].w = s[i];
    x[tot].pos = i;
    x[tot].opt = 1;
    tot++;
    x[tot].w = e[i];
    x[tot].pos = i;
    x[tot].opt = 2;
  }
  for (i = 1; i <= n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      if (check(k[i], k[j])) {
        swap(k[i], k[j]);
      }
    }
  }
  int pos;
  sort(x + 1, x + 1 + tot, cmp);
  for (i = 1; i <= tot; i++) {
    pos = x[i].pos;
    if (x[i].opt == 1)
      s[pos] = i;
    else
      e[pos] = i;
  }
  for (i = 1; i <= n; i++) add(s[i], 1);
  int ans = 0;
  int l, r;
  for (i = 1; i <= n; i++) {
    j = k[i];
    l = s[j];
    r = e[j];
    if (l > r) swap(l, r);
    if (d[j] == 0) continue;
    ans += sum(r - 1) - sum(l);
    add(s[j], -1);
    add(e[j], 1);
  }
  printf("%d", ans);
}
