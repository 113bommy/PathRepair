#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5, LOG = 19, off = 1 << 19;
pair<int, int> t[LOG][2 * off];
void upd(int x, pair<int, int> p, int lg) {
  for (x += off; x; x /= 2) {
    t[lg][x].first = min(t[lg][x].first, p.first);
    t[lg][x].second = max(t[lg][x].second, p.second);
  }
}
pair<int, int> get(int x, int lo, int hi, int a, int b, int lg) {
  if (lo >= a && hi <= b) {
    return t[lg][x];
  }
  if (lo >= b || hi <= a) {
    return {off, 0};
  }
  int mid = (lo + hi) >> 1;
  pair<int, int> lson = get(x * 2, lo, mid, a, b, lg);
  pair<int, int> rson = get(x * 2 + 1, mid, hi, a, b, lg);
  return pair<int, int>(min(lson.first, rson.first),
                        max(lson.second, rson.second));
}
int r[MAXN];
pair<int, int> par[MAXN][LOG];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  if (n == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < 2 * off; ++i)
    for (int lg = 0; lg < LOG; ++lg) {
      t[lg][i].first = off;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 3; ++j) {
      par[i + j * n][0].first = max(0, i + j * n - r[i]);
      par[i + j * n][0].second = min(3 * n - 1, i + j * n + r[i]);
      upd(i + j * n, par[i + j * n][0], 0);
    }
  for (int lg = 1; lg < LOG; ++lg) {
    for (int i = n; i < 2 * n; ++i) {
      par[i][lg] = get(1, 0, off, par[i][lg - 1].first,
                       par[i][lg - 1].second + 1, lg - 1);
    }
    for (int i = 0; i < n; ++i) {
      par[i][lg].first = max(0, par[i + n][lg].first - n);
      par[i][lg].second = min(3 * n - 1, par[i + n][lg].second - n);
    }
    for (int i = 2 * n; i < 3 * n; ++i) {
      par[i][lg].first = max(0, par[i - n][lg].first + n);
      par[i][lg].second = min(3 * n - 1, par[i - n][lg].second + n);
    }
    for (int i = 0; i < 3 * n; ++i) {
      upd(i, par[i][lg], lg);
    }
  }
  for (int j = 0; j < n; ++j) {
    int i = n + j;
    int lo = i, hi = i, sol = 0;
    for (int lg = LOG - 1; lg >= 0; --lg) {
      pair<int, int> res = get(1, 0, off, lo, hi + 1, lg);
      if (res.second - res.first + 1 < n) {
        lo = res.first;
        hi = res.second;
        sol += (1 << lg);
      }
    }
    cout << sol + 1 << endl;
  }
}
