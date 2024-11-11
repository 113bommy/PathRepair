#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <class T>
void ckmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
void ckmin(T &x, const T &y) {
  if (x > y) x = y;
}
long long absl(long long x) { return x < 0 ? -x : x; }
const int N = 114;
long long p[N], v[N], sp[N];
void solve() {
  long long n = read(), k = read();
  long long B = k * k + 1;
  long long c = (n - 1) / B;
  memset(p, 0, sizeof(p)), memset(sp, 0, sizeof(sp)), memset(v, 0, sizeof(v));
  for (long long i = c; i; i /= k) p[++*p] = i % k, v[*p] = i;
  v[*p + 1] = 0;
  sp[*p + 1] = k * (k + 1) / 2;
  for (int i = (*p); i <= (1); i++) {
    long long L = v[i + 1] * B + p[i] * k + 1;
    long long R = L + k - 1;
    long long coef = 0;
    if (L >= sp[i + 1])
      coef = k;
    else if (R >= sp[i + 1])
      coef = R - sp[i + 1] + 1;
    sp[i] = v[i + 1] * B * k + p[i] * k * k + k * (k + 1) / 2 + coef;
  }
  long long d, e;
  if (n == sp[1]) {
    if (c == 0) {
      cout << k + 1 << endl;
      return;
    }
    c = v[2];
    d = p[1];
    e = k + 1;
  } else {
    long long nd = n - c * B - (n > sp[1]) - 1;
    d = nd / k, e = nd % k + 1;
  }
  long long res = c * (k * (k + 1)) + d * (k + 1) + e;
  cout << res << endl;
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}
