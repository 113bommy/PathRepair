#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 * 1000;
const int MAXK = 20;
const int INF = 1000 * 1000 * 1000;
int a[MAXN + 2];
int l[MAXN + 2][MAXK];
int r[MAXN + 2][MAXK];
int cntl[MAXN + 2], cntr[MAXN + 2];
set<pair<int, int> > is;
long long two[MAXK + 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  two[0] = 1;
  for (int i = 1; i < MAXK + 10; i++) two[i] = two[i - 1] * 2;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cntl[i] = cntr[i] = 1;
    l[i][0] = r[i][0] = i;
  }
  a[0] = a[n + 1] = INF;
  is.insert(make_pair(-a[0], 0));
  for (int i = 1; i <= n + 1; i++) {
    auto it = is.insert(make_pair(-a[i], i)).first;
    it++;
    while (it != is.end()) {
      r[it->second][cntr[it->second]++] = i;
      if (cntr[it->second] == MAXK) {
        auto buf = it;
        it++;
        is.erase(buf);
      } else {
        it++;
      }
    }
  }
  is.clear();
  is.insert(make_pair(-a[n + 1], n + 1));
  for (int i = n; i >= 0; i--) {
    auto it = is.insert(make_pair(-a[i], i)).first;
    it++;
    while (it != is.end()) {
      l[it->second][cntl[it->second]++] = i;
      if (cntl[it->second] == MAXK) {
        auto buf = it;
        it++;
        is.erase(buf);
      } else {
        it++;
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < MAXK; j++) {
      for (int L = 0; L <= min(j, cntl[i] - 1); L++) {
        int R = j - L;
        if (cntr[i] - 1 > R) {
          int cntl = l[i][L] - l[i][L + 1], cntr = r[i][R + 1] - r[i][R];
          ans += (double)cntl * cntr * a[i] / two[j + 1];
        }
      }
    }
  }
  cout.setf(ios::fixed);
  cout.precision(20);
  cout << ans / n / n;
  return 0;
}
