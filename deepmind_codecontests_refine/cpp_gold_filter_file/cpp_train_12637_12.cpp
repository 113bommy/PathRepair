#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0, o = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') o = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * o;
}
long long d[100005], a[100005], t[100005], s[100005];
long long f[105][100005];
int q[100005];
long long X(int j, int k, int r) {
  return f[r - 1][j] - f[r - 1][k] + s[j] - s[k];
}
long long Y(int j, int k) { return j - k; }
int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  d[0] = 0;
  for (int i = 2; i <= n; i++) d[i] = d[i - 1] + read();
  for (int i = 1; i <= m; i++) {
    long long x = read();
    a[i] = read() - d[x];
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= m; i++) f[1][i] = i * a[i] - s[i];
  for (int k = 2; k <= p; k++) {
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
      while (l < r && X(q[l + 1], q[l], k) < a[i] * Y(q[l + 1], q[l])) l++;
      if (l <= r) {
        int j = q[l];
        f[k][i] = f[k - 1][j] + (i - j) * a[i] - (s[i] - s[j]);
      }
      while (l < r && X(q[r], q[r - 1], k) * Y(q[r], i) <=
                          X(q[r], i, k) * Y(q[r], q[r - 1]))
        r--;
      q[++r] = i;
    }
  }
  printf("%I64d\n", f[p][m]);
  return 0;
}
