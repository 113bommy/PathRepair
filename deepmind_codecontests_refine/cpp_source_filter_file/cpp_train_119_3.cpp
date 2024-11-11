#include <bits/stdc++.h>
using namespace std;
long long int fast(long long int n, long long int a, long long int m) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else {
    long long int r = fast(n / 2, a, m);
    if (n % 2 == 0) {
      return (((r % m) * (r % m)) % m);
    } else {
      return (((((r % m) * a) % m) * r) % m);
    }
  }
}
long long int po2[21];
long long int len(long long int n) {
  long long int p = 0;
  while (n > 0) {
    p++;
    n /= 10;
  }
  return p;
}
int main() {
  po2[0] = 1;
  for (long long int i = 1; i <= 20; i++) {
    po2[i] = ((po2[i - 1] % 998244353) * (10 % 998244353)) % 998244353;
  }
  long long int n, i, j, k;
  cin >> n;
  long long int A[n], d[12] = {0};
  for (i = 0; i < n; i++) {
    cin >> A[i];
    d[len(A[i])]++;
  }
  long long int ans = 0;
  for (i = 0; i < n; i++) {
    vector<long long int> dp;
    long long int res = A[i];
    while (res > 0) {
      dp.push_back(res % 10);
      res /= 10;
    }
    long long int lenr = dp.size();
    reverse(dp.begin(), dp.end());
    for (j = 1; j <= lenr; j++) {
      long long int r = 0, g;
      for (k = 1; k <= lenr - j + 1; k++) {
        g = ((dp[k - 1] % 998244353) * (po2[lenr + j - k] % 998244353)) %
            998244353;
        r = (r % 998244353 + g % 998244353) % 998244353;
      }
      long long int f = 1;
      for (k = lenr; k >= lenr - j + 2; k--) {
        g = ((dp[k - 1] % 998244353) * (po2[f] % 998244353)) % 998244353;
        r = (r % 998244353 + g % 998244353) % 998244353;
        f += 2;
      }
      long long int tot = ((d[j] % 998244353) * (r % 998244353)) % 998244353;
      ans = (ans % 998244353 + tot % 998244353) % 998244353;
    }
    for (j = lenr + 1; j <= 9; j++) {
      long long int r = 0, f = 1, g;
      for (k = lenr; k >= 1; k--) {
        g = ((dp[k - 1] % 998244353) * (po2[f] % 998244353)) % 998244353;
        r = (r % 998244353 + g % 998244353) % 998244353;
        f += 2;
      }
      long long int tot = (d[j] * r) % 998244353;
      ans = (ans % 998244353 + tot % 998244353) % 998244353;
    }
  }
  for (i = 0; i < n; i++) {
    vector<long long int> dp;
    long long int res = A[i];
    while (res > 0) {
      dp.push_back(res % 10);
      res /= 10;
    }
    long long int lenp = dp.size();
    reverse(dp.begin(), dp.end());
    for (j = lenp; j <= 9; j++) {
      long long int r = 0, g = 0;
      for (k = lenp; k >= 1; k--) {
        long long int d =
            ((dp[k - 1] % 998244353) * (po2[g] % 998244353)) % 998244353;
        r = (r % 998244353 + d % 998244353) % 998244353;
        g += 2;
      }
      long long int tot = ((d[j] % 998244353) * (r % 998244353)) % 998244353;
      ans = (ans % 998244353 + tot % 998244353) % 998244353;
    }
    for (j = 1; j < lenp; j++) {
      long long int r = 0, g;
      for (k = 1; k <= lenp - j; k++) {
        g = ((dp[k - 1] % 998244353) * (po2[lenp + j - k] % 998244353)) %
            998244353;
        r = (r % 998244353 + g % 998244353) % 998244353;
      }
      long long int f = 0;
      for (k = lenp; k >= lenp - j + 1; k--) {
        g = ((dp[k - 1] % 998244353) * (po2[f] % 998244353)) % 998244353;
        r = (r % 998244353 + g % 998244353) % 998244353;
        f += 2;
      }
      long long int tot = ((d[j] % 998244353) * (r % 998244353)) % 998244353;
      ans = (ans % 998244353 + tot % 998244353) % 998244353;
    }
  }
  cout << ans;
}
