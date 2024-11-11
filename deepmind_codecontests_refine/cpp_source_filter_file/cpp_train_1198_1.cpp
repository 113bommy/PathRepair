#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long Q = 2e5 + 5;
const long long M = 1e6 + 5;
const long long SZ = sqrt(N) + 1;
struct data {
  long long l, r, idx;
} qr[Q];
long long n, q, a[N], k;
long long freq[M], ans[Q], cur = 0;
bool comp(struct data &d1, struct data &d2) {
  long long b1 = d1.l / SZ;
  long long b2 = d2.l / SZ;
  if (b1 != b2)
    return b1 < b2;
  else
    return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}
inline void add(long long x) {
  cur += freq[x ^ k];
  freq[x]++;
}
inline void remove(long long x) {
  freq[x]--;
  cur -= freq[x ^ k];
}
void mo() {
  sort(qr + 1, qr + q + 1, comp);
  long long l = 0, r = 0;
  cur = 0;
  freq[0] = 1;
  for (long long i = 1; i <= q; i++) {
    while (l < qr[i].l) remove(a[l++]);
    while (l > qr[i].l) add(a[--l]);
    while (r < qr[i].r) add(a[++r]);
    while (r > qr[i].r) remove(a[r--]);
    ans[qr[i].idx] = cur;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1];
  for (long long i = 1; i <= q; i++) {
    cin >> qr[i].l >> qr[i].r;
    --qr[i].l;
    qr[i].idx = i;
  }
  mo();
  for (long long i = 1; i <= q; i++) cout << ans[i] << '\n';
}
