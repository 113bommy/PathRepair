#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
struct Line {
  long long k, b;
  long long get(long long x) { return k * x + b; }
} Q[400010];
int n, tot;
long long a[400010], sum[400010], Ans, delta;
bool check(long long A, long long B, long long C) {
  Line a = Q[A], b = Q[B], c = Q[C];
  return (a.b - c.b) * (a.k - b.k) <= (b.b - a.b) * (c.k - a.k);
}
void add(long long k, long long b) {
  Q[++tot] = Line{k, b};
  while (tot > 2 && check(tot - 1, tot - 2, tot))
    Q[tot - 1] = Q[tot - 2], tot--;
}
long long query(long long x) {
  int l = 0, r = tot;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (Q[mid].get(x) <= Q[mid + 1].get(x))
      l = mid;
    else
      r = mid;
  }
  return Q[r].get(x);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read(), sum[i] = sum[i - 1] + a[i], Ans += a[i] * i;
  for (int r = 2; r <= n; r++) {
    add(r - 1, -sum[r - 2]);
    delta = max(delta, query(a[r]) + sum[r - 1] - a[r] * r);
  }
  tot = 0;
  memset(Q, 0, sizeof(Q));
  for (int l = n - 1; l >= 1; l--) {
    add(-(l + 1), -sum[l + 1]);
    delta = max(delta, query(-a[l]) + sum[l] - a[l] * l);
  }
  printf("%lld", Ans + delta);
  return 0;
}
