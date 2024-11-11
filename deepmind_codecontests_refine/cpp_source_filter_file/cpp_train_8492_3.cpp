#include <bits/stdc++.h>
using namespace std;
const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;
int n, m;
int a[MAXN], Q[MAXN], cnt[MAXN], ans[MAXN];
int f[MAXN];
void prework() {}
void read() {}
int gao(int k) {
  if (f[k] != -1) return f[k];
  int ret = 0;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] == 0) {
      if (now == k) {
        ret++;
        while (now) {
          cnt[Q[now--]] = 0;
        }
        now = 1;
        Q[now] = a[i];
        cnt[a[i]] = 1;
      } else {
        Q[++now] = a[i];
        cnt[a[i]] = 1;
      }
    } else {
      ;
    }
  }
  ret += (now > 0);
  while (now) {
    cnt[Q[now--]] = 0;
  }
  return f[k] = ret;
}
void work(int l, int r) {
  if (l >= r || gao(l) == gao(r)) {
    for (int i = l; i <= r; i++) ans[i] = f[l];
    return;
  }
  m = (l + r) >> 1;
  work(l, m);
  work(m + 1, r);
}
void solve(int casi) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= n; i++) f[i] = -1;
  work(1, n);
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
void printans() {}
int main() {
  prework();
  int T = 1;
  for (int i = 1; i <= T; i++) {
    read();
    solve(i);
    printans();
  }
  return 0;
}
