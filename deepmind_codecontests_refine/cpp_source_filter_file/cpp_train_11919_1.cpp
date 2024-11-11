#include <bits/stdc++.h>
using namespace std;
int b[1010], T, t, k, a[1010], p, q, n;
pair<int, int> v[1010];
int main() {
  cin >> n >> T;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].first >> v[i].second;
    v[i].first = T - v[i].first;
  }
  sort(v + 1, v + n + 1);
  p = n;
  for (int i = T; i >= 1; --i) {
    t = 0;
    while (v[p].first == i) {
      a[++t] = v[p].second;
      --p;
    }
    if (!t) continue;
    sort(a + 1, a + t + 1);
    if (i <= 10 && (t > (1 << i))) {
      int dif = t - (1 << i);
      for (int j = 1; j <= t; ++j) a[j] = a[j + dif];
      t -= dif;
    }
    k = 0;
    for (int j = t; j >= 1; j -= 2) b[++k] = a[j] + a[j - 1];
    while (k) {
      v[++p] = make_pair(i - 1, b[k]);
      k--;
    }
  }
  cout << v[1].second;
  return 0;
}
