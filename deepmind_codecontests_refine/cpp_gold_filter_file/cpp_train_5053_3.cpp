#include <bits/stdc++.h>
using namespace std;
long long n, ara[500005], k, ara2[500005];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long l, h, i, j, m, z, t, o, a, b;
  cin >> n >> k;
  a = 0;
  for (i = 0; i < n; i++) cin >> ara[i];
  l = 1;
  h = 3000000000;
  z = 0;
  while (l < h) {
    m = (l + h) / 2;
    t = 0;
    for (i = 0; i < n; i++) t += max(m - ara[i], z);
    if (t <= k)
      l = m + 1;
    else
      h = m - 1;
  }
  o = 1;
  for (j = (max(o, l - 50)); j < l + 50; j++) {
    t = 0;
    for (i = 0; i < n; i++) t += max(j - ara[i], z);
    if (t > k) {
      if (j == 1)
        l = j;
      else
        l = j - 1;
      break;
    }
  }
  t = 0;
  for (i = 0; i < n; i++) {
    t += max(l - ara[i], z);
    ara[i] = max(ara[i], l);
  }
  for (i = 0; i < n; i++) {
    if (ara[i] == l && k != t) {
      ara[i]++;
      t++;
    }
  }
  l = 1;
  h = 3000000000;
  z = 0;
  while (l < h) {
    m = (l + h) / 2;
    t = 0;
    for (i = 0; i < n; i++) t += max(ara[i] - m, z);
    if (t <= k)
      h = m;
    else
      l = m + 1;
  }
  for (j = h + 50; j >= max(o, h - 50); j--) {
    t = 0;
    for (i = 0; i < n; i++) t += max(ara[i] - j, z);
    if (t > k) {
      l = j + 1;
      break;
    }
  }
  t = 0;
  for (i = 0; i < n; i++) {
    t += max(ara[i] - l, z);
    ara[i] = min(ara[i], l);
  }
  for (i = 0; i < n; i++) {
    if (ara[i] == l && k != t) {
      ara[i]--;
      t++;
    }
  }
  sort(ara, ara + n);
  cout << ara[n - 1] - ara[0];
  return 0;
}
