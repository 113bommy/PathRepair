#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
int deg[N], d[N];
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &deg[i]);
  }
}
int check(int bob) {
  for (int i = 1; i < n; i++) {
    d[i] = deg[i];
  }
  d[n] = bob;
  sort(d + 1, d + n + 1);
  reverse(d + 1, d + n + 1);
  long long pre = 0;
  long long suf = 0;
  int lef = n;
  for (int k = 1; k <= n; k++) {
    pre += d[k];
    while (lef >= 1 && d[lef] < k) {
      lef--;
    }
    suf -= min(d[k], k);
    suf += max(lef - k + 1, 0);
    if (pre > 1ll * k * (k - 1) + suf) {
      return d[k] <= bob;
    }
  }
  return 2;
}
int find_lower(int R, int tag) {
  int L = 0;
  int res = -1;
  while (L <= R) {
    int M = (L + R) >> 1;
    int r = check(M * 2 + tag);
    if (r == 1 || r == 2) {
      if (r == 2) {
        res = M;
      }
      R = M - 1;
    } else {
      L = M + 1;
    }
  }
  return res;
}
int find_upper(int L, int tag) {
  int R = (n - 1) / 2;
  int res = L;
  while (L <= R) {
    int M = (L + R) >> 1;
    if (check(M * 2 + tag) == 2) {
      res = M;
      L = M + 1;
    } else {
      R = M - 1;
    }
  }
  return res;
}
void solve() {
  int cnt = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cnt += deg[i] & 1;
    sum += deg[i];
  }
  n++;
  int l = find_lower((n - 1) / 2, cnt % 2);
  if (l == -1) {
    puts("-1");
    return;
  }
  int r = find_upper(l, cnt % 2);
  for (int i = l; i <= r; i++) printf("%d ", i * 2 + cnt % 2);
  puts("");
}
int main() {
  input();
  solve();
  return 0;
}
