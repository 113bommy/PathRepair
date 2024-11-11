#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long double ans[100500];
int main() {
  long long n, len, v1, v2;
  cin >> n >> len >> v1 >> v2;
  long long first;
  for (int i = 0; i < n; i++) {
    int k1;
    cin >> k1;
    if (i == 0) first = k1;
    a.push_back(k1 - first);
  }
  long double l = 0;
  long double L = (len * 1.0 / (v1 + v2) * v1);
  long double r = L;
  int cnt = 0;
  while (cnt < n && a[cnt] < r) {
    cnt++;
  }
  int nextr = cnt;
  cnt--;
  int nextl = 1;
  do {
    nextr = nextr % n;
    nextl = nextl % n;
    long double distl = a[nextl] - l;
    long double distr = a[nextr] - r;
    if (distl <= 0) distl = 2 * len - l + a[nextl];
    if (distr <= 0) distr = 2 * len - r + a[nextr];
    if (distl < distr) {
      l = a[nextl];
      r = l + L;
      if (r >= 2 * len) r -= 2 * len;
      ans[cnt] += distl / (2 * len);
      cnt--;
      nextl++;
    } else if (distr < distl) {
      r = a[nextr];
      l = r - L;
      if (l < 0) l = 2 * len + l;
      ans[cnt] += distr / (2 * len);
      cnt++;
      nextr++;
    } else {
      r = a[nextr];
      l = r - L;
      if (l < 0) l = 2 * len + l;
      ans[cnt] += distr / (2 * len);
      nextr++;
      nextl++;
    }
  } while (l != 0);
  for (int i = 0; i <= n; i++) {
    cout << setbase(ios_base::fixed) << setprecision(40) << ans[i] << endl;
  }
  return 0;
}
