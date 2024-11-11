#include <bits/stdc++.h>
using namespace std;
int n, m;
int pri[6001], pn, fl[6001];
void ola() {
  for (int i = 2; i <= n; i++) {
    if (!fl[i]) pri[++pn] = i;
    for (int j = 1; j <= pn && i * pri[j] <= n; j++) {
      fl[i * pri[j]] = 1;
      if (i % pri[j]) break;
    }
  }
}
int ans[6001];
bool check(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void work(int x) {
  int a, b;
  for (int i = 2; i <= x; i++)
    if (check(i) && check(x - i)) {
      a = i;
      b = x - i;
      break;
    }
  for (int i = 1; i <= n && a > n; i++)
    if (!ans[i]) ans[i] = 1, a -= ans[i];
  ans[a] = 1;
  for (int i = 1; i <= n; i++)
    if (!ans[i]) ans[i] = 2;
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
void solve() {
  scanf("%d", &n);
  m = n * (n + 1) / 2;
  if (n == 1) {
    printf("-1\n");
    return;
  }
  ola();
  if (check(m)) {
    for (int i = 1; i <= n; i++) printf("1%c", " \n"[i == n]);
    return;
  }
  if (m & 1) {
    if (check(m - 2)) {
      printf("1 2 ");
      for (int i = 3; i <= n; i++) printf("1%c", " \n"[i == n]);
      return;
    } else {
      ans[3] = 3;
      work(m - 3);
    }
  } else
    work(m);
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
