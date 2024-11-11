#include <bits/stdc++.h>
using namespace std;
const int nmax = 200005;
struct tt {
  int first, second, third;
};
bool comp(tt unu, tt doi) {
  if (unu.first == doi.first) return unu.second < doi.second;
  return unu.first < doi.first;
}
tt a[2 * nmax];
int aib[2][nmax];
int n, i, j, dp, x, wh, mx;
inline int lbit(int x) { return (((x ^ (x - 1)) & x)); }
void update(int wh, int poz, int val) {
  for (int idx = poz; idx <= n; idx += lbit(idx))
    aib[wh][idx] = max(aib[wh][idx], val);
}
int compute(int wh, int poz) {
  int ret = 0;
  for (int idx = poz; idx > 0; idx -= lbit(idx)) ret = max(ret, aib[wh][idx]);
  return ret;
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[i] = {x - i, i, 0};
    a[n + i] = {x - i + 1, i, 1};
  }
  sort(a + 1, a + 2 * n + 1, comp);
  for (i = 1; i <= 2 * n; i++) {
    wh = a[i].third;
    if (wh == 0) {
      dp = compute(0, a[i].second) + 1;
    } else {
      dp = max(compute(0, a[i].second - 2), compute(1, a[i].second)) + 1;
    }
    update(wh, a[i].second, dp);
    if (dp > mx) mx = dp;
  }
  cout << max(0, n - mx - 1);
  return 0;
}
