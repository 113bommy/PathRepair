#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) {
    if (ch == '-') f = -1;
  }
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - 48;
  }
  return x * f;
}
const int mxN = 1e5;
const int lgA = 58;
const int INF = 1e8;
int f[lgA + 3][mxN + 3];
long long a[mxN + 3];
int b[mxN + 3], s1[mxN + 3], s0[mxN + 3];
int n, k;
bool cmp(int x, int y) {
  return (a[x] & ((1ll << k) - 1)) < (a[y] & ((1ll << k) - 1));
}
void updmin(int &x, const int y) { x = min(x, y); }
int main() {
  scanf("%d", &n);
  long long mx = 0ll;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= n; i++) a[i] = mx - a[i];
  sort(a + 1, a + n + 1);
  memset(f, 42, sizeof(f));
  f[0][n] = 0;
  for (k = 0; k < lgA; k++) {
    for (int i = 1; i <= n; i++) b[i] = i;
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
      s1[i] = s1[i - 1] + ((a[b[i]] >> k) & 1), s0[i] = i - s1[i];
    for (int i = 0; i <= n; i++) {
      if (f[k][i] > INF) continue;
      updmin(f[k + 1][s0[n] + i - s0[i]], f[k][i] + s0[n] + i - 2 * s0[i]);
      updmin(f[k + 1][s0[i]], f[k][i] + s1[n] - s1[i] + s0[i]);
    }
  }
  printf("%d\n", f[lgA][n]);
  return 0;
}
