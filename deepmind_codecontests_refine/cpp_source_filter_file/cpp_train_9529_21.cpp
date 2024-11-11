#include <bits/stdc++.h>
using namespace std;
const int MOD = 786433, MAXN = 1 << 18, LOGN = 18, MAXM = 5005;
inline void S(int& n) {
  n = 0;
  int ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
  }
  n = n * sign;
}
const int SHIFT = 30, ETF = MOD - 1, LIM = (int)1e9;
const long long int INF = (long long int)1e18 + 1;
const double PI = (double)acos(-1), EPSILON = 1e-10;
int main() {
  int n;
  long long int k;
  S(n);
  scanf("%lld", &k);
  long long int a[n + 1];
  long long int mod2coeff[n + 1];
  long long int prev = 0;
  bool remZero[n + 1];
  bool soFar = true;
  for (int i = 0; i < n + 1; i++) {
    scanf("%lld", &a[i]);
    prev += a[i];
    if (i == n) {
      mod2coeff[i] = prev;
    } else {
      mod2coeff[i] = prev % 2;
      prev /= 2;
    }
    remZero[i] = (soFar & (mod2coeff[i] == 0));
    soFar = remZero[i];
  }
  int idx = -1;
  long long int val = 0;
  for (int i = n; i >= 0; i--) {
    val = val * 2 + mod2coeff[i];
    if (remZero[i]) {
      idx = i + 1;
      val -= mod2coeff[i];
      val /= 2;
      break;
    }
    if (abs(val) > 2 * k) {
      idx = i;
      break;
    }
  }
  if (idx <= 0 || remZero[idx - 1] == false) {
    printf("0\n");
  } else {
    int ans = 0;
    for (int i = idx; i >= 0; i--) {
      if (abs(val) > 2 * k) break;
      long long int newcoeff = a[i] - val;
      if (abs(newcoeff) <= k) {
        if (i < n || (i == n && newcoeff != 0)) ans++;
      }
      val *= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
