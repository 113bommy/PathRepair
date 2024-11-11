#include <bits/stdc++.h>
using namespace std;
int qq, n, m, k;
long long INF = 998244353;
struct st {
  int l;
  int r;
};
long long bin_pow(long long base, long long p) {
  if (p == 1) {
    return base;
  }
  if (p % 2 == 0) {
    long long t = bin_pow(base, p / 2);
    return t * t % INF;
  } else {
    return bin_pow(base, p - 1) * base % INF;
  }
}
int main() {
  long long ans = 0, anp = 0, x1 = 0, x2 = 0, kp = 0;
  cin >> n >> k;
  vector<int> v1(n), v2(n);
  vector<long long> f(n + 1), pp(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> v1[i] >> v2[i];
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = (i * f[i - 1]) % INF;
  for (int i = k; i <= n; i++) {
    pp[i] = f[i] * bin_pow(f[i - k] * f[k] % INF, INF - 2) % INF;
  }
  int j = 0, i = 0;
  while (i < n) {
    if (v1[i] <= v2[j]) {
      kp++;
      i++;
      if (kp >= k) {
        ans = (ans + pp[kp] - pp[kp - 1]) % INF;
      }
    }
    while (i != n && v1[i] > v2[j]) {
      ;
      kp--;
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
