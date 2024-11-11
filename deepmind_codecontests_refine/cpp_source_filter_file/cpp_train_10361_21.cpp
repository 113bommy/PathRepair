#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
const float f = acos(-1);
map<long long, int> mp;
long long bit[mm], b[mm], r[mm], h[mm], vol[mm], dp[mm];
long long maxi;
int p, n, k;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &r[i], &h[i]);
    vol[i] = r[i] * r[i] * h[i];
    b[i] = vol[i];
  }
  sort(b, b + n);
  mp[b[0]] = 1;
  p = 1;
  for (int i = 1; i < n; i++)
    if (b[i] != b[i - 1]) {
      p++;
      mp[b[i]] = p;
    }
  for (int i = 0; i < n; i++) {
    maxi = 0;
    k = mp[vol[i]];
    while (k > 0) {
      maxi = max(maxi, bit[k]);
      k = k - (k & (-k));
    }
    dp[i] = maxi + vol[i];
    k = mp[vol[i]];
    while (k <= 200000) {
      bit[k] = max(bit[k], dp[i]);
      k = k + (k & (-k));
    }
  }
  maxi = 0;
  for (int i = 0; i < n; i++) maxi = max(maxi, dp[i]);
  printf("%f", maxi * f);
  return 0;
}
