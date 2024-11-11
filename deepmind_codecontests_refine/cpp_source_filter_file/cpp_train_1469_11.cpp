#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long dr[800000];
long long pr[800000];
long long sf[800000];
long long w[800000];
long long a[800000];
void bl(long long v, long long l, long long r) {
  if (r == l + 1) {
    dr[v] = w[l];
    pr[v] = 0;
    sf[v] = 0;
    return;
  }
  bl(2 * v + 1, l, (l + r) / 2);
  bl(2 * v + 2, (l + r) / 2, r);
  dr[v] = dr[2 * v + 1] + dr[2 * v + 2];
  pr[v] = pr[2 * v + 1] + pr[2 * v + 2] +
          (a[r - 1] - (r - (l + r) / 2) - a[(r + l) / 2 - 1]) *
              (dr[2 * v + 1] % MOD);
  sf[v] = sf[2 * v + 1] + sf[2 * v + 2] +
          (a[(r + l) / 2] - a[l] - ((r + l) / 2 - l)) * (dr[2 * v + 2] % MOD);
  sf[v] %= MOD;
  pr[v] %= MOD;
}
void ch(long long v, long long l, long long r, long long id, long long x) {
  if (r == l + 1 && l == id) {
    dr[v] = x;
    pr[v] = 0;
    sf[v] = 0;
    return;
  }
  if (r <= id || l > id) {
    return;
  }
  ch(2 * v + 1, l, (l + r) / 2, id, x);
  ch(2 * v + 2, (l + r) / 2, r, id, x);
  dr[v] = dr[2 * v + 1] + dr[2 * v + 2];
  pr[v] = pr[2 * v + 1] + pr[2 * v + 2] +
          (a[r - 1] - (r - (l + r) / 2) - a[(r + l) / 2 - 1]) *
              (dr[2 * v + 1] % MOD);
  sf[v] = sf[2 * v + 1] + sf[2 * v + 2] +
          (a[(r + l) / 2] - a[l] - ((r + l) / 2 - l)) * (dr[2 * v + 2] % MOD);
  sf[v] %= MOD;
  pr[v] %= MOD;
}
long long sm(long long v, long long l, long long r, long long ln,
             long long rn) {
  if (ln >= r || rn <= l) {
    return 0;
  }
  if (ln <= l && r <= rn) {
    return dr[v];
  }
  return sm(2 * v + 1, l, (l + r) / 2, ln, rn) +
         sm(2 * v + 2, (l + r) / 2, r, ln, rn);
}
pair<long long, long long> indd(long long v, long long l, long long r,
                                long long k, long long ln, long long rn) {
  if (ln >= r || rn <= l) {
    return {0, -1};
  }
  if (l == r - 1) {
    return {dr[v], l};
  }
  if (ln <= l && r <= rn) {
    if (dr[v] < k) return {dr[v], r};
  }
  pair<long long, long long> cr =
      indd(2 * v + 1, l, (l + r) / 2, k, ln, min(rn, (l + r) / 2));
  if (cr.first < k) {
    pair<long long, long long> cr2 =
        indd(2 * v + 2, (l + r) / 2, r, k - cr.first, max(ln, (l + r) / 2), rn);
    return {cr2.first + cr.first, cr2.second};
  } else {
    return cr;
  }
}
long long prr(long long v, long long l, long long r, long long ln,
              long long k) {
  if (ln >= r || k <= l) {
    return 0;
  }
  if (ln <= l && r <= k) {
    return (pr[v] + (a[k - 1] - (k - r) - a[r - 1]) * (dr[v] % MOD)) % MOD;
  }
  return (prr(2 * v + 1, l, (l + r) / 2, ln, k) +
          prr(2 * v + 2, (l + r) / 2, r, ln, k)) %
         MOD;
}
long long sff(long long v, long long l, long long r, long long k,
              long long rn) {
  if (k >= r || rn <= l) {
    return 0;
  }
  if (k <= l && r <= rn) {
    return (sf[v] + (a[l] - a[k] - (l - k)) * (dr[v] % MOD)) % MOD;
  }
  return (sff(2 * v + 1, l, (l + r) / 2, k, rn) +
          sff(2 * v + 2, (l + r) / 2, r, k, rn)) %
         MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  bl(0, 0, n);
  for (int i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    if (x < 0) {
      ch(0, 0, n, -x - 1, y);
    } else {
      x--;
      long long aaa = (sm(0, 0, n, x, y)) / 2;
      long long L = indd(0, 0, n, aaa, x, y).second;
      cout << (prr(0, 0, n, x, L + 1) + sff(0, 0, n, L, y)) % MOD << endl;
    }
  }
}
