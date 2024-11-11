#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int a[1010][1010];
long long C[1010 * 1000], R[1010 * 1000];
long long c, r;
priority_queue<long long> qc, qr;
int main() {
  int T;
  while (~scanf("%d%d%d%d", &n, &m, &k, &p)) {
    while (!qc.empty()) qc.pop();
    while (!qr.empty()) qr.pop();
    for (int i = 1; i <= n; i++) {
      r = 0;
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        r += a[i][j];
      }
      qr.push(r);
    }
    long long v;
    R[0] = 0;
    for (int i = 1; i <= k; i++) {
      R[i] = (v = qr.top()) + R[i - 1];
      qr.pop();
      qr.push(v - m * p);
    }
    for (int j = 1; j <= m; j++) {
      c = 0;
      for (int i = 1; i <= n; i++) c += a[i][j];
      qc.push(c);
    }
    C[0] = 0;
    for (int i = 1; i <= k; i++) {
      C[i] = C[i - 1] + (v = qc.top());
      qc.pop();
      qc.push(v - n * p);
    }
    long long res = -(1LL << 60);
    for (int i = 0; i <= k; i++)
      res = max(res, C[i] + R[k - i] - ((long long)i * (k - i) * p));
    printf("%d\n", res);
  }
  return 0;
}
