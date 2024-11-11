#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long big = 1e17;
int c[200010], d[200010];
bool check(int r, int d) {
  return (r >= 1900 and d == 1) or (r < 1900 and d == 2);
}
int main() {
  int n, ones = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i] >> d[i];
    if (d[i] == 1) ones++;
  }
  int first2, first1;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 2) {
      first2 = i;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 1) {
      first1 = i;
      break;
    }
  }
  if (ones == n) {
    cout << "Infinity";
    return 0;
    ;
  } else if (!ones) {
    int maxp = 0, maxx = 0;
    for (int i = 1; i <= n; ++i) {
      maxp = max(maxp, maxx + c[i]);
      maxx += c[i];
    }
    int ini = 1899 - maxp;
    for (int i = 1; i <= n; ++i) {
      ini += c[i];
    }
    cout << ini;
  } else {
    if (d[1] == 1) {
      int ini = 1899;
      int minn = inf;
      for (int i = first2 - 1; i >= 1; --i) {
        ini -= c[i];
        if (ini < 1900) {
          cout << "Impossible";
          return 0;
        }
        minn = min(minn, ini - 1900);
      }
      int maxans = -inf;
      for (int rating = ini; rating >= ini - minn; rating--) {
        int r = rating, f = 0;
        for (int i = 1; i <= n; ++i) {
          if (!check(r, d[i])) {
            f = 1;
            break;
          }
          r += c[i];
        }
        if (f) continue;
        maxans = max(maxans, r);
      }
      if (maxans == -inf)
        cout << "Impossible";
      else
        cout << maxans;
    } else {
      int ini = 1900;
      int minn = inf;
      for (int i = first1 - 1; i >= 1; --i) {
        ini -= c[i];
        if (ini >= 1900) {
          cout << "Impossible";
          return 0;
        }
        minn = min(minn, 1899 - ini);
      }
      int maxans = -inf;
      for (int rating = ini; rating <= ini + minn; rating++) {
        int r = rating, f = 0;
        for (int i = 1; i <= n; ++i) {
          if (!check(r, d[i])) {
            f = 1;
            break;
          }
          r += c[i];
        }
        if (f) continue;
        maxans = max(maxans, r);
      }
      if (maxans == -inf)
        cout << "Impossible";
      else
        cout << maxans;
    }
  }
  return 0;
}
