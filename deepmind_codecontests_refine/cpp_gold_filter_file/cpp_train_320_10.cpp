#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200020], w[200020];
const long long mod = 1e9 + 7;
long long sw[200020], s[200020];
void add(int pos, int val) {
  int x = a[pos];
  for (; pos <= n; pos += pos & -pos) {
    sw[pos] += val;
    s[pos] = (s[pos] + 1ll * x * val) % mod;
  }
}
long long query_sw(int x) {
  long long sum = 0;
  for (; x; x -= x & -x) sum += sw[x];
  return sum;
}
long long query_s(int x) {
  long long sum = 0;
  for (; x; x -= x & -x) sum = (sum + s[x]) % mod;
  return sum;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) {
    sw[i] = sw[i - 1] + w[i];
    s[i] = (s[i - 1] + 1ll * w[i] * a[i]) % mod;
  }
  for (int i = n; i >= 1; i--) {
    sw[i] -= sw[i - (i & -i)];
    s[i] = (s[i] - s[i - (i & -i)] + mod) % mod;
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      x = -x;
      add(x, y - w[x]);
      w[x] = y;
    } else {
      int l = x - 1, r = y - 1;
      long long L = query_sw(x - 1), R = query_sw(y);
      while (l < r) {
        int m = l + r + 1 >> 1;
        long long cur = query_sw(m);
        if (2 * cur < L + R)
          l = m;
        else
          r = m - 1;
      }
      assert(x <= l + 1 && l + 1 <= y);
      long long ans = (2 * query_sw(l) - L - R) % mod * a[l + 1] % mod;
      ans = (ans + query_s(y) + query_s(x - 1) - 2 * query_s(l)) % mod;
      if (ans < 0) ans += mod;
      cout << ans << endl;
    }
  }
}
