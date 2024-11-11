#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5, bs = 2, mxM = 1 << 4;
int n, k, q, a[mxN + 1], b[mxN + 1], c[mxN + 1], a1, a2, d[mxN], e[mxN], s,
    l[mxN], r[mxN], pi, vi, bc[(mxN - 1) / bs + 1][mxM], lz[(mxN - 1) / bs + 1];
char qt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    c[i - 1] = a[i] ^ a[i - 1] ^ b[i] ^ b[i - 1];
    if (i > k) c[i - 1] ^= c[i - 1 - k];
  }
  c[n] = c[n - k] ^ a[n] ^ b[n];
  for (int i = 0; i < k; ++i) {
    for (int j = i; j <= n - k; j += k) {
      e[s] = c[j];
      a1 += e[s] > 0;
      ++bc[s / bs][e[s]];
      l[j] = s++;
      r[j] = l[j] + (n - k - j) / k;
    }
  }
  for (int i = n - k + 1; i <= n; ++i) {
    a2 += c[i] > 0;
    d[i % k] = c[i];
  }
  cout << (a2 ? -1 : a1) << "\n";
  while (q--) {
    cin >> qt >> pi >> vi, --pi;
    if (qt == 'a') {
      vi ^= a[pi + 1];
      a[pi + 1] ^= vi;
    } else {
      vi ^= b[pi + 1];
      b[pi + 1] ^= vi;
    }
    for (int i = pi; i <= pi + 1; ++i) {
      if (i <= n - k) {
        int li = l[i];
        auto pb = [&](int i) {
          for (int j = i * bs; j < min((i + 1) * bs, s); ++j) {
            --bc[i][e[j]];
            e[j] ^= lz[i];
            ++bc[i][e[j]];
          }
          lz[i] = 0;
        };
        pb(li / bs);
        pb(r[i] / bs);
        auto ue = [&](int i) {
          --bc[i / bs][e[i]];
          a1 += !e[i];
          e[i] ^= vi;
          ++bc[i / bs][e[i]];
          a1 -= !e[i];
        };
        for (; li % bs && li <= r[i]; ++li) ue(li);
        for (; li + bs <= r[i]; li += bs) {
          a1 += bc[li / bs][lz[li / bs]];
          lz[li / bs] ^= vi;
          a1 -= bc[li / bs][lz[li / bs]];
        }
        for (; li <= r[i]; ++li) ue(li);
      }
      a2 += !d[i % k];
      d[i % k] ^= vi;
      a2 -= !d[i % k];
    }
    cout << (a2 ? -1 : a1) << "\n";
  }
}
