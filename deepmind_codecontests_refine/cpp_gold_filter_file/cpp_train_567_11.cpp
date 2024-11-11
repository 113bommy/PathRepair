#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 3e5 + 34;
long long d[N], h[N];
long long t[N * 2][2];
long long c[N][2];
long long n;
void add(int v, int l, int r, int p, long long x, int num) {
  if (l + 1 == r) {
    t[v][num] = x;
    return;
  }
  int m = (l + r) / 2;
  if (p < m)
    add(v * 2 + 1, l, m, p, x, num);
  else
    add(v * 2 + 2, m, r, p, x, num);
  long long r1 = c[t[v * 2 + 1][num]][num];
  long long r2 = c[t[v * 2 + 2][num]][num];
  if (r1 > r2)
    t[v][num] = t[v * 2 + 1][num];
  else
    t[v][num] = t[v * 2 + 2][num];
}
long long getmax(int v, int l, int r, int L, int R, int num) {
  if (l >= R || L >= r) return 2 * n;
  if (L <= l && r <= R) return t[v][num];
  int m = (l + r) / 2;
  long long i1 = getmax(v * 2 + 1, l, m, L, R, num);
  long long i2 = getmax(v * 2 + 2, m, r, L, R, num);
  long long r1 = c[i1][num];
  long long r2 = c[i2][num];
  if (r1 > r2)
    return i1;
  else
    return i2;
}
long long sum, num, a, b, m, i1, i2, res;
int main() {
  scanf("%I64d %I64d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d", &d[i]);
  for (int i = 0; i < n; i++) scanf("%I64d", &h[i]);
  for (int i = 0; i < N * 2; i++) t[i][0] = t[i][1] = n * 2;
  c[n * 2][0] = c[n * 2][1] = -INF;
  for (int i = 0; i < n * 2; i++) {
    c[i][0] = sum + 2 * h[i % n];
    c[i][1] = 2 * h[i % n] - sum;
    add(0, 0, 2 * n, i, i, 0);
    add(0, 0, 2 * n, i, i, 1);
    sum += d[i % n];
  }
  while (m--) {
    scanf("%I64d %I64d", &a, &b);
    a--;
    b--;
    if (a <= b) a += n;
    b++;
    i1 = getmax(0, 0, 2 * n, b, a, 0);
    i2 = getmax(0, 0, 2 * n, b, a, 1);
    if (i1 != i2)
      res = c[i1][0] + c[i2][1];
    else {
      res = max(c[getmax(0, 0, 2 * n, b, i1, 0)][0],
                c[getmax(0, 0, 2 * n, i1 + 1, a, 0)][0]) +
            c[i2][1];
      res = max(res, c[i1][0] + max(c[getmax(0, 0, 2 * n, b, i2, 1)][1],
                                    c[getmax(0, 0, 2 * n, i2 + 1, a, 1)][1]));
    }
    printf("%I64d\n", res);
  }
  return 0;
}
