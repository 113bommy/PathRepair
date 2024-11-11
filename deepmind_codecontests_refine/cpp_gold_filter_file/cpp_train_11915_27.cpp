#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> a;
priority_queue<long long> b;
long long sa[1000013];
long long sb[1000013];
int h[1013][1013];
int n, m, k, p;
void fix(priority_queue<long long> q, long long v[1000013], int r) {
  for (int i = 1; i < k + 1; ++i) {
    long long va = q.top();
    v[i] = v[i - 1] + va;
    q.pop();
    q.push(va - p * r);
  }
}
long long solve(long long v[1000013], long long w[1000013], int a, int b) {
  long long ret = v[k];
  for (int i = k; i >= 0; --i) {
    long long crt =
        v[i] + w[k - i] - ((long long)i) * ((long long)k - i) * (long long)p;
    ret = max(ret, crt);
  }
  return ret;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &h[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    long long su = 0;
    for (int j = 0; j < m; ++j) {
      su += h[i][j];
    }
    a.push(su);
  }
  for (int j = 0; j < m; ++j) {
    long long su = 0;
    for (int i = 0; i < n; ++i) {
      su += h[i][j];
    }
    b.push(su);
  }
  fix(a, sa, m);
  fix(b, sb, n);
  long long ret = max(solve(sa, sb, n, m), solve(sb, sa, m, n));
  printf("%lld", ret);
  return 0;
}
