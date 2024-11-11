#include <bits/stdc++.h>
using namespace std;
const int N = 100012;
int n, a[N], pos[N], pre[N], suc[N], l[N], r[N], ans = 0, x[N], y[N];
struct Heap {
  int d[N], home[N], tot;
  inline void exchange(int i, int j) {
    swap(d[i], d[j]);
    swap(home[i], home[j]);
    pos[home[i]] = i;
    pos[home[j]] = j;
  }
  inline void up(int i) {
    for (int j = i >> 1; j && d[i] > d[j]; i = j, j = i >> 1) exchange(i, j);
  }
  inline void down(int i) {
    for (int j = i * 2; j <= tot; i = j, j = i * 2) {
      if (j < tot && d[j + 1] > d[j]) ++j;
      if (d[j] > d[i])
        exchange(i, j);
      else
        break;
    }
  }
  inline void insert(int k, int x) {
    pos[k] = ++tot;
    home[tot] = k;
    d[tot] = x;
    up(tot);
  }
  inline int top() { return home[1]; }
  inline void remove(int k) {
    exchange(k, tot);
    --tot;
    up(k);
    down(k);
  }
} H;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), pre[i] = i - 1, suc[i] = i + 1, l[i] = r[i] = i;
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n; ++i) H.insert(i, a[i]);
  for (int i = 1; i < n; ++i) {
    int now = H.top();
    if (a[pre[now]] > a[suc[now]]) {
      for (int j = 1; j <= a[now] - a[pre[now]]; ++j)
        ++ans, x[ans] = l[now], y[ans] = r[now];
      H.remove(1);
      H.remove(pos[pre[now]]);
      r[pre[now]] = r[now];
      suc[pre[now]] = suc[now];
      pre[suc[now]] = pre[now];
      H.insert(pre[now], a[pre[now]]);
    } else {
      for (int j = 1; j <= a[now] - a[suc[now]]; ++j)
        ++ans, x[ans] = l[now], y[ans] = r[now];
      a[now] = a[suc[now]];
      H.remove(1);
      H.remove(pos[suc[now]]);
      r[now] = r[suc[now]];
      suc[now] = suc[suc[now]];
      pre[suc[now]] = now;
      H.insert(now, a[now]);
    }
  }
  int now = H.top();
  for (int i = 1; i <= a[now]; ++i) ++ans, x[ans] = l[now], y[ans] = r[now];
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("%d %d\n", x[i], y[i]);
}
