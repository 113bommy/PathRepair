#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const int maxn = 123456;
int n, l, r;
int ql, qr;
int ans;
int res = 1000000000;
int a[maxn];
int b[maxn];
void solve() {
  scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ans += r * a[i];
  }
  b[0] = ans;
  for (int i = 0; i < n; i++) {
    b[i + 1] = b[i] + (l - r) * a[i];
  }
  for (int i = 0; i < n; i++) {
    if ((i << 1) != n) {
      if ((i << 1) < n) {
        b[i] += (n - 1 - (i << 1)) * qr;
      } else {
        b[i] += ((i << 1) - n - 1) * ql;
      }
    }
    res = min(res, b[i]);
  }
  printf("%d", res);
}
int main() { solve(); }
