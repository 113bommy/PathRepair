#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * w;
}
int n, q, a[200005];
char c[200005];
const int Base = 19260817;
const int mod = 998244353;
int bas[200005], cnt[200005], h1[200005], h2[200005];
int query(int l, int r) {
  if (l & 1)
    return (h1[r] - 1ll * h1[l - 1] * bas[cnt[r] - cnt[l - 1]] % mod + mod) %
           mod;
  else
    return (h2[r] - 1ll * h2[l - 1] * bas[cnt[r] - cnt[l - 1]] % mod + mod) %
           mod;
}
int main() {
  cin >> n;
  scanf("%s", c);
  for (int i = 1; i <= n; i++) a[i] = c[i - 1] - '0';
  bas[0] = 1;
  for (int i = 1; i <= n; i++) {
    bas[i] = 1ll * bas[i - 1] * Base % mod;
    cnt[i] = cnt[i - 1] + (a[i] == 0);
    if (a[i] == 0) {
      h1[i] = (1ll * h1[i - 1] * Base + (i & 1)) % mod;
      h2[i] = (1ll * h2[i - 1] * Base + (i & 1 ^ 1)) % mod;
    } else {
      h1[i] = h1[i - 1], h2[i] = h2[i - 1];
    }
  }
  cin >> q;
  while (q--) {
    int l, r, len;
    cin >> l >> r >> len;
    if (query(l, l + len - 1) == query(r, r + len - 1))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
