#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, d[siz], a[siz], tree[4 * siz];
bool primes[siz], done[siz];
vector<long long> have[siz];
void build(long long par, long long l, long long r) {
  if (l == r) {
    tree[par] = a[l];
    return;
  }
  long long mid = l + r >> 1;
  build(2 * par, l, mid);
  build(2 * par + 1, mid + 1, r);
  tree[par] = tree[2 * par] + tree[2 * par + 1];
}
void upd(long long par, long long l, long long r, long long L, long long R) {
  if (done[par]) return;
  if (l > R or r < L) return;
  if (l == r) {
    tree[par] = d[a[l]];
    a[l] = d[a[l]];
    if (a[l] <= 2) done[par] = 1;
    return;
  }
  long long mid = l + r >> 1;
  upd(2 * par, l, mid, L, R);
  upd(2 * par + 1, mid + 1, r, L, R);
  tree[par] = tree[2 * par] + tree[2 * par + 1];
  done[par] = (done[2 * par] and done[2 * par + 1]);
}
long long get_sum(long long par, long long l, long long r, long long L,
                  long long R) {
  if (r < L or l > R) return 0;
  if (l >= L and r <= R) return tree[par];
  long long mid = l + r >> 1;
  return get_sum(2 * par, l, mid, L, R) +
         get_sum(2 * par + 1, mid + 1, r, L, R);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 2; i < siz; i++) {
    if (primes[i]) continue;
    for (long long j = i; j < siz; j += i) {
      long long num = j, cnt = 0;
      while (num % i == 0) num /= i, cnt++;
      primes[j] = 1;
      have[j].push_back(cnt);
    }
  }
  d[1] = 1;
  d[2] = 2;
  for (long long i = 3; i < siz; i++) {
    long long num = 1;
    for (auto x : have[i]) num *= (x + 1);
    d[i] = num;
  }
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (m--) {
    long long op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      upd(1, 1, n, l, r);
      continue;
    }
    long long ans = get_sum(1, 1, n, l, r);
    cout << ans << endl;
  }
}
