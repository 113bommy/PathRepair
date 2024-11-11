#include <bits/stdc++.h>
using namespace std;
void shikhar7s(long long int cas) {
  long long int n, i;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int l, r, s, e, j, c[200], m, ans = 1;
  memset(c, 0, sizeof(c));
  for (i = 0; i < 200; i++) {
    s = -1;
    e = n;
    m = -1;
    while (s < e) {
      l = s;
      r = e;
      s++;
      e--;
      m++;
      while (s < e && (a[s] != i + 1 || a[e] != i + 1)) {
        if (a[s] == i + 1)
          e--;
        else if (a[e] == i + 1)
          s++;
        else {
          s++;
          e--;
        }
      }
    }
    m *= 2;
    long long int ma = 0;
    for (j = l + 1; j < r; j++) {
      c[a[j] - 1]++;
      ma = max(ma, c[a[j] - 1]);
    }
    s = l;
    e = r;
    while (s >= 0 && e < n) {
      ans = max(ans, ma + m);
      s--;
      e++;
      c[i] += 2;
      ma = max(ma, c[i]);
      while (s >= 0 && e < n && (a[s] != i + 1 || a[e] != i + 1)) {
        if (a[s] == i + 1) {
          c[a[e] - 1]++;
          ma = max(ma, c[a[e] - 1]);
          e++;
        } else if (a[e] == i + 1) {
          c[a[s] - 1]++;
          ma = max(ma, c[a[s] - 1]);
          s--;
        } else {
          c[a[e] - 1]++;
          ma = max(ma, c[a[e] - 1]);
          c[a[s] - 1]++;
          ma = max(ma, c[a[s] - 1]);
          s--;
          e++;
        }
      }
      m -= 2;
    }
    for (j = 0; j < 200; j++) c[i] = 0;
  }
  cout << ans << "\n";
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  long long int t = 1;
  cin >> t;
  long long int cas = 1;
  while (cas <= t) {
    shikhar7s(cas);
    cas++;
  }
  return 0;
}
