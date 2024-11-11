#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[111111];
long long p[111111], rev[111111];
int n, N;
long long ans = 0;
long long pwr(long long x, int y) {
  if (!y) return 1;
  long long tmp = pwr(x, y / 2);
  tmp = tmp * tmp % 1000000007;
  if (y & 1) tmp = tmp * x % 1000000007;
  return tmp;
}
long long C(int x, int y) {
  if (x < y) return 1;
  return p[x] * rev[y] % 1000000007 * rev[x - y] % 1000000007;
}
void Fate(int s, int pos) {
  int l = pos, r = pos;
  long long res = 1;
  for (int i = s; i <= N; ++i) {
    int d = a[i].first - a[i - 1].first - 1, x = a[i].second;
    if (l <= x && x <= r) return;
    if (x < l) {
      int d2 = l - x - 1;
      if (d2 > d) return;
      res = res * C(d, d2) % 1000000007;
      l = x;
      r = l + a[i].first - 1;
    } else {
      int d2 = x - r - 1;
      if (d2 > d) return;
      res = res * C(d, d2) % 1000000007;
      r = x;
      l = r - a[i].first + 1;
    }
  }
  ans = ans + res;
  ans %= 1000000007;
}
int main() {
  a[0].first = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x) a[++N] = make_pair(x, i);
  }
  a[++N] = make_pair(n + 1, n + 1);
  sort(a + 1, a + 1 + N);
  p[0] = 1;
  ++n;
  for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * i % 1000000007;
  rev[0] = 1;
  for (int i = 1; i <= n; ++i) rev[i] = pwr(p[i], 1000000007 - 2);
  if (a[1].first == 1)
    Fate(2, a[1].second);
  else
    for (int i = 1; i <= n; ++i) Fate(1, i);
  cout << ans << endl;
}
