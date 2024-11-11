#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;
int a[N], b[N];
int mi[N], ma[N];
int lowbit(int x) { return x & -x; }
void up(int c) {
  while (c < N) {
    b[c] += 1;
    c += lowbit(c);
  }
}
int vis[N], sm[N], lst[N];
int q(int c) {
  int rs = 0;
  while (c) {
    rs += b[c];
    c -= lowbit(c);
  }
  return rs;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) ma[i] = mi[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    mi[a[i]] = 1;
    if (vis[a[i]] == 0) {
      ma[a[i]] = max(ma[a[i]], a[i] + q(n) - q(a[i]));
      up(a[i]);
    }
    vis[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (vis[i] == 0) ma[i] = max(ma[i], i + q(n) - q(i));
  memset(b, 0, sizeof b);
  for (int i = 1; i <= m; i++) {
    if (lst[a[i]]) {
      ma[a[i]] =
          max(ma[a[i]], i - lst[a[i]] - (q(m + 1 - lst[a[i]]) - q(m + 1 - i)));
      up(m + 1 - lst[a[i]]);
    }
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (lst[i]) {
      ma[i] = max(ma[i], m - lst[i] - q(m + 1 - lst[i]) + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", mi[i], ma[i]);
  }
}
