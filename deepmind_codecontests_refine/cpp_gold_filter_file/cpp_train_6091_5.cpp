#include <bits/stdc++.h>
using namespace std;
long long n, k, st[400005][15], a[100005], res;
void update(long long node, long long l, long long r, long long pos,
            long long val, long long k) {
  if (pos < l || pos > r) return;
  if (l == r) {
    st[node][k] = val;
    return;
  }
  update(node * 2, l, (l + r) / 2, pos, val, k);
  update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val, k);
  st[node][k] = st[node * 2][k] + st[node * 2 + 1][k];
}
long long get(long long node, long long l, long long r, long long u,
              long long v, long long k) {
  if (v < l || u > r) return 0;
  if (u <= l && r <= v) return st[node][k];
  long long x = get(node * 2, l, (l + r) / 2, u, v, k);
  long long y = get(node * 2 + 1, (l + r) / 2 + 1, r, u, v, k);
  return x + y;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  k++;
  if (k == 1) {
    cout << n;
    return 0;
  }
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    update(1, 1, n, a[i], 1, 1);
    for (long long j = 1; j <= k; j++) {
      long long temp = get(1, 1, n, 1, a[i] - 1, j);
      if (j == k - 1) res += temp;
      update(1, 1, n, a[i], temp, j + 1);
    }
  }
  cout << res;
}
