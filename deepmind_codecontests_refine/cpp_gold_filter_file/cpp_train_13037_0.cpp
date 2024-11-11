#include <bits/stdc++.h>
using namespace std;
int main() {
  char d;
  int a[200000], b, i, j, k, l, r, s, m[200], n, q, ans, e, u, si, sj;
  cin >> q;
  while (q--) {
    cin >> n;
    ans = 0;
    vector<vector<int>> v(200);
    for (i = 0; i < 200; ++i) m[i] = 0;
    for (i = 0; i < n; ++i) {
      cin >> b;
      m[b - 1]++;
      v[b - 1].push_back(i);
    }
    for (i = 0; i < 200; ++i) v[i].push_back(1000000);
    for (i = 0; i < 200; ++i) {
      for (j = i; j < 200; j++) {
        if (m[i] == 0 || m[j] == 0) continue;
        if (i == j) {
          ans = max(ans, m[i]);
        } else {
          si = 0;
          sj = 0;
          k = m[i] + m[j];
          for (e = 0; e < k; ++e) {
            if (v[i][si] < v[j][sj]) {
              a[e] = 1;
              si++;
            } else {
              a[e] = 2;
              sj++;
            }
          }
          for (e = 0; e <= k / 2; ++e) {
            if (2 * e > m[i]) break;
            s = 0;
            l = 0;
            r = k - 1;
            while (s != e) {
              if (a[l] == 1) ++s;
              ++l;
            }
            s = 0;
            while (s != e) {
              if (a[r] == 1) ++s;
              --r;
            }
            s = 0;
            for (u = l; u <= r; ++u)
              if (a[u] == 2) ++s;
            ans = max(ans, 2 * e + s);
          }
          for (e = 0; e <= k / 2; ++e) {
            if (2 * e > m[j]) break;
            s = 0;
            l = 0;
            r = k - 1;
            while (s != e) {
              if (a[l] == 2) ++s;
              ++l;
            }
            s = 0;
            while (s != e) {
              if (a[r] == 2) ++s;
              --r;
            }
            s = 0;
            for (u = l; u <= r; ++u)
              if (a[u] == 1) ++s;
            ans = max(ans, 2 * e + s);
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
