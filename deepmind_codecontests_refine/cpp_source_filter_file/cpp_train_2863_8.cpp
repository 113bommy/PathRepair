#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7, prime = 13;
int tree[4 * N], pw[N], lazy[4 * N], pre[11][N], a[N], s[N];
void build(int i, int l, int r) {
  if (l == r) return void(tree[i] = s[l]);
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  tree[i] = ((tree[i << 1] * 1ll * pw[r - mid]) % mod + tree[i << 1 | 1]) % mod;
}
void propagte(int i, int l, int r) {
  if (lazy[i] == -1) return;
  tree[i] = (lazy[i] * 1ll * a[r - l]) % mod;
  if (l != r) {
    lazy[1 << i] = lazy[1 << i | 1] = lazy[i];
  }
  lazy[i] = -1;
}
void update(int i, int l, int r, int a, int b, int c) {
  propagte(i, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    lazy[i] = c;
    propagte(i, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(i << 1, l, mid, a, b, c);
  update(i << 1 | 1, mid + 1, r, a, b, c);
  tree[i] = ((tree[i << 1] * 1ll * pw[r - mid]) % mod + tree[i << 1 | 1]) % mod;
}
int n, m, k;
void get(int i, int l, int r, int a, int b, int &ans) {
  if (b >= n || b < a) return void(ans = -1);
  propagte(i, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    ans = (ans * 1ll * pw[r - l + 1]) % mod;
    ans = (ans + tree[i]) % mod;
    return;
  }
  int mid = (l + r) >> 1;
  get(i << 1, l, mid, a, b, ans);
  get(i << 1 | 1, mid + 1, r, a, b, ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1, a[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = (pw[i - 1] * 1ll * prime) % mod;
    a[i] = pw[i] + a[i - 1];
    if (a[i] >= mod) a[i] -= mod;
  }
  string tem;
  cin >> n >> m >> k >> tem;
  for (int i = 0; i < n; i++) s[i] = tem[i] - '0' + 1;
  build(1, 0, n - 1);
  memset(lazy, -1, sizeof lazy);
  for (int i = 0, l, r, t, d; i < m + k; i++) {
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> d;
      l--, r--, d++;
      update(1, 0, n - 1, l, r, d);
    } else {
      cin >> l >> r >> d;
      l--, r--;
      if (l == r) {
        cout << "YES\n";
        continue;
      }
      int s1 = 0, s2 = 0;
      get(1, 0, n - 1, l, r - d, s1);
      get(1, 0, n - 1, l + d, r, s2);
      if (s1 == s2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
