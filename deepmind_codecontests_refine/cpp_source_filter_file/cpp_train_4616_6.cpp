#include <bits/stdc++.h>
using namespace std;
const int max_n = 1005;
const long long inf = LLONG_MAX;
int t, n;
long long p[max_n], V, res;
int a[max_n], b[max_n], c[max_n];
long long ra, rb, rc, P[max_n][max_n];
map<long long, long long> Mr, Ma, Mb, Mc;
void func(long long A, long long B, long long X, int s) {
  if (A * B * B > V) return;
  if (s == n) {
    long long C = V / (A * B);
    long long ret = 2ll * (A * B + B * C + A * C);
    if (ret < res) {
      res = ret;
      ra = A;
      rb = B;
      rc = C;
    }
    return;
  }
  for (int i = a[s] - b[s] - c[s]; i >= 0; i--) {
    c[s] += i;
    func(A, B * P[s][i], X, s + 1);
    c[s] -= i;
  }
}
void rec(long long A, int s) {
  if (A * A * A > V) return;
  if (s == n) {
    long long X = sqrt(V / A);
    if (!(A > cbrt(V) or 2ll * (2ll * A * X + V / A) >= res))
      func(A, 1ll, X, 0);
    return;
  }
  for (int i = a[s]; i >= 0; i--) {
    b[s] += i;
    rec(A * P[s][i], s + 1);
    b[s] -= i;
  }
}
int main() {
  scanf("%d", &t);
  for (int z = 0; z < t; z++) {
    V = 1ll;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> a[i];
      P[i][0] = 1ll;
      for (int j = 0; j < a[i]; j++) {
        V *= p[i];
        P[i][j + 1] = P[i][j] * p[i];
      }
    }
    res = inf;
    if (Mr[V]) {
      res = Mr[V];
      ra = Ma[V];
      rb = Mb[V];
      rc = Mc[rc];
    } else
      rec(1ll, 0);
    Mr[V] = res;
    Ma[V] = ra;
    Mb[V] = rb;
    Mc[V] = rc;
    cout << res << " " << ra << " " << rb << " " << rc << "\n";
  }
  return 0;
}
