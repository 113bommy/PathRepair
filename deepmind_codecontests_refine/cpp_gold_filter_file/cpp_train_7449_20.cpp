#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 200003, mod = 1e9 + 7;
const long long inf = (1e18 + 11);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  long long a[n + 1], i, j, c1 = 0;
  set<pair<long long, int> > s;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < 0) ++c1;
    s.insert({abs(a[i]), i});
  }
  if (c1 % 2 == 0) {
    tie(j, i) = *s.begin();
    s.erase(s.begin());
    if (!j) {
      s.insert({x, i});
      a[i] = -x;
      --k;
      ++c1;
    } else {
      if (a[i] < 0) {
        j *= -1;
        while (j <= 0) {
          if (!k) break;
          j += x;
          --k;
        }
        a[i] = j;
        s.insert({abs(j), i});
        --c1;
      } else {
        while (j >= 0) {
          if (!k) break;
          j -= x;
          --k;
        }
        a[i] = j;
        s.insert({abs(j), i});
        ++c1;
      }
    }
  }
  while (k--) {
    tie(j, i) = *s.begin();
    s.erase(s.begin());
    if (a[i] < 0) {
      j *= -1;
      j -= x;
      a[i] = j;
      s.insert({abs(j), i});
    } else {
      j += x;
      a[i] = j;
      s.insert({abs(j), i});
    }
  }
  for (i = 1; i <= n; ++i) cout << a[i] << ' ';
  return 0;
}
