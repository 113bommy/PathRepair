#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int nmax = 100001;
long long res, cnt = 1e+9 + 7;
long long a, b, c, n, t, m, k, l, r, x;
long long p_a[nmax], p_b[nmax];
pair<long long, long long> el[nmax];
int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> p_a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> el[i].first;
    el[i].second = i;
  }
  sort(el + 1, el + n + 1);
  k = 0;
  for (int i = 1; i <= n; ++i) {
    x = el[i].second;
    if (k == 0) {
      p_b[x] = l;
      ++k;
      t = l - p_a[x];
    } else {
      p_b[x] = t + p_a[x] + 1;
      t = p_b[x] - p_a[x];
      if (p_b[x] < l) {
        p_b[x] = l;
        t = max(t, p_b[x] - p_a[x]);
      }
      ++k;
    }
    if (p_b[x] > r) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << p_b[i] << " ";
  }
  return 0;
}
