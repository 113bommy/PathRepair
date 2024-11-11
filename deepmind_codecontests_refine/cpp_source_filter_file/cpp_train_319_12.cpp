#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
int n, a[N], b[N], c[N * 64], l[N * 64], r[N * 64], st[N][25], lg[N];
long long ans;
int rmq(int i, int j) {
  int k = lg[j - i + 1];
  return max(st[i][k], st[j - (1 << k) + 1][k]);
}
int main() {
  if (fopen("E.in", "r")) freopen("E.in", "r", stdin);
  scanf("%d\n", &n);
  for (int i = 1; (1 << i) <= n; i++) {
    lg[1 << i] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (lg[i] == 0) {
      lg[i] = lg[i - 1];
    }
    long long x;
    scanf("%lld ", &x);
    a[i] = __builtin_popcountll(x);
    st[i][0] = a[i];
    b[i] = a[i] + b[i - 1];
    if (l[b[i]] == 0) {
      l[b[i]] = i;
    }
    r[b[i]] = i;
  }
  for (int i = N * 64 - 3; i >= 0; i--) {
    c[i] = c[i + 2];
    if (l[i] == 0) continue;
    c[i] += r[i] - l[i] + 1;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 64; j += 2) {
      int x = l[b[i] + j];
      int y = r[b[i] + j];
      if (x == 0) continue;
      if (b[y] != b[i] + j) {
        cout << "wtf";
        return 0;
      }
      if (j >= 2 * rmq(i + 1, y)) {
        ans += y - max(x, i) + 1;
      }
    }
    ans += c[b[i] + 66];
  }
  cout << ans;
  return 0;
}
