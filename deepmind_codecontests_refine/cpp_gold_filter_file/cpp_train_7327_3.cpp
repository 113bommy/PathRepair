#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, m, k;
long long cnt[MAXN];
long long fac2[MAXN];
const long long MODER = 1000000007;
int main(int argc, const char* argv[]) {
  fac2[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fac2[i] = fac2[i - 1] * 2LL;
    fac2[i] %= MODER;
  }
  scanf(" %d %d %d", &n, &m, &k);
  bool legal = true;
  int cl = n + 1, cr = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf(" %d %d", &u, &v);
    if (u + 1 == v) {
      continue;
    } else if (u + k + 1 == v) {
      cl = min(cl, u);
      cr = max(cr, u);
      cnt[u]++;
      if (cnt[u] > 1) legal = false;
    } else {
      legal = false;
    }
  }
  if (cr - cl > k) legal = false;
  if (!legal) {
    puts("0");
  } else {
    long long res = !cr;
    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i + k + 1 <= n; i++) {
      if (i <= cl && min(i + k, n - k - 1) >= cr) {
        res += fac2[(min(i + k, n - k - 1) - i) -
                    (cnt[min(i + k, n - k - 1)] - cnt[i])];
        res %= MODER;
      }
    }
    res %= MODER;
    cout << res << endl;
  }
  return 0;
}
