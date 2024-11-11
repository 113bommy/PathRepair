#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x;
}
int n, m, sum, k, cnt;
int minn, maxx;
int num[1000010], a[1000010], b[1000010], c[1000010], d[1000010];
bool vis[1000010], f[1000010];
int fa[1000010];
int find(int x) {
  if (fa[x] != x) return fa[x] = find(fa[x]);
  return x;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) fa[i] = i, num[i] = 1;
  int x, fx, fy;
  for (int i = 1; i <= n; i++) {
    x = read();
    fx = find(x);
    fy = find(i);
    if (fx == fy) continue;
    num[fx] += num[fy];
    fa[fy] = fx;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[x = find(i)]) {
      vis[x] = true;
      a[++cnt] = num[x];
    }
  sort(a + 1, a + cnt + 1);
  k = m;
  int s;
  for (int i = 1; i <= cnt; i++) {
    s = a[i] / 2;
    if (k >= s) {
      maxx += s * 2;
      k -= s;
    } else {
      maxx += k * 2;
      k = 0;
    }
    if (a[i] & 1) sum++;
  }
  maxx += min(k, sum);
  minn = m;
  sum = 0;
  for (int i = 1; i <= cnt; i++)
    if (a[i] == a[i - 1])
      c[sum]++;
    else
      c[++sum] = 1, d[sum] = a[i];
  cnt = 0;
  for (int i = 1; i <= sum; i++) {
    for (int j = 1; c[i]; j <<= 1) {
      int t = min(c[i], j);
      a[++cnt] = d[i] * j;
      c[i] -= t;
    }
  }
  f[0] = true;
  for (int i = 1; i <= cnt; i++)
    for (int j = m - a[i]; j >= 0; j--)
      if (f[j] == true) f[j + a[i]] = true;
  if (f[m] == false) minn++;
  printf("%d %d\n", minn, maxx);
  return 0;
}
