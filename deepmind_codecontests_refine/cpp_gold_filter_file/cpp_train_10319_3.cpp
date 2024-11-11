#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long int modexpo(long long int x, long long int y) {
  if (y == 0) return 1;
  if (y % 2) {
    long long int v = modexpo(x, y / 2);
    return (((x * v) % mod) * v) % mod;
  } else {
    long long int v = modexpo(x, y / 2);
    return (v * v) % mod;
  }
}
long long int fact[1000011];
long long int ncr(long long int n, long long int r) {
  long long int p = (fact[r] * fact[n - r]) % mod;
  return (fact[n] * modexpo(p, mod - 2)) % mod;
}
int main() {
  long long int t, i, j, k, l, m, n, q, r, d, x = 0, y;
  scanf("%lld%lld", &n, &t);
  long long int a[n];
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  long long int mi = a[0];
  vector<long long int> pre;
  pre.push_back(a[0]);
  for (i = 1; i < n; i++) {
    mi = min(a[i], mi);
    pre.push_back(pre[i - 1] + a[i]);
  }
  long long int ans = 0;
  long long int rest = t;
  if (t >= pre[n - 1]) {
    long long int tim = t / pre[n - 1];
    ans += tim * n;
    rest = t - tim * pre[n - 1];
  }
  vector<long long int> temp;
  long long int su = 0;
  for (i = 0; i < n; i++)
    if (a[i] <= rest) {
      temp.push_back(a[i]);
      su += a[i];
    }
  while (1) {
    if (temp.size() == 0) break;
    if (temp.size() == 1) {
      long long int tim = rest / temp[0];
      ans += tim;
      break;
    }
    if (rest >= su) {
      long long int tim = rest / su;
      ans += tim * temp.size();
      rest -= tim * su;
      continue;
    }
    for (i = 0; i < temp.size(); i++) {
      if (temp[i] <= rest) {
        ans++;
        rest -= temp[i];
      }
    }
    vector<long long int> tt;
    su = 0;
    for (i = 0; i < temp.size(); i++)
      if (temp[i] <= rest) {
        tt.push_back(temp[i]);
        su += a[i];
      }
    temp = tt;
  }
  printf("%lld\n", ans);
  return 0;
}
