#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
long long h[100010], a[100010];
long long l[100010];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k >> p;
  for (int i = 0; i < (n); i++) cin >> h[i] >> a[i];
  for (int i = 0; i < (n); i++) {
    l[i] = h[i] + a[i] * m;
  }
  long long lo = 0, hi = 2e13;
  while (lo + 1 < hi) {
    long long mi = (lo + hi) / 2;
    bool ok = 1;
    long long total = 0;
    for (int i = 0; i < (n); i++) {
      total += max(0LL, (l[i] - mi + p - 1) / p);
    }
    if (total > m * k) {
      ok = 0;
    } else {
      int t[10010] = {};
      for (int i = 0; i < (n); i++)
        if (l[i] > mi) {
          for (long long target = (l[i] - mi) % p == 0 ? p : (l[i] - mi) % p;
               target <= l[i] - mi; target += p) {
            if (target - h[i] <= 0) {
              t[0]++;
            } else if (target - h[i] > a[i] * (m - 1)) {
              ok = 0;
              goto end;
            } else {
              t[(target - h[i] + a[i] - 1) / a[i]]++;
            }
          }
        }
      int rest = 0;
      for (int i = 0; i < (m); i++) {
        rest += t[i];
        rest = max(0, rest - k);
      }
      ok = rest == 0;
    }
  end:;
    (ok ? hi : lo) = mi;
  }
  cout << hi << endl;
}
