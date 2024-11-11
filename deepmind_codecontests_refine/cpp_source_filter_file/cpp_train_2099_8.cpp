#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::swap;
long long la, n, p[32], a[1000005], ans, w[32], s[100005];
bool ins(long long x) {
  long long now = x;
  for (long long i = 31; ~i; i--) {
    if (!(x >> i)) continue;
    if (!p[i]) {
      return p[i] = x, w[i] = now, 0;
    }
    if (w[i] > now) {
      swap(p[i], x);
      swap(w[i], now);
    }
    x ^= p[i];
  }
  return 1;
}
void sol(long long x) {
  if (x == -1) return;
  sol(x - 1);
  a[++la] ^= w[x];
  sol(x - 1);
}
signed main() {
  memset(w, 0x3f, sizeof(w));
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> s[i], ins(s[i]);
  long long ans = 0;
  while (p[ans]) ans++;
  ans--;
  while (ans >= 0 && w[ans] >= (1 << (ans + 1))) ans--;
  cout << ans + 1 << endl;
  sol(ans);
  for (long long i = 0; i < (1 << (ans + 1)); i++) {
    cout << a[i] << " ";
    a[i + 1] ^= a[i];
  }
}
