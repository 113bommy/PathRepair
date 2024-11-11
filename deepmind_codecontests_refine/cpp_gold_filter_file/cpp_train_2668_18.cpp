#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e7 + 5;
long long int power(long long int base, long long int exp) {
  long long int res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    res %= mod;
    base %= mod;
    exp /= 2;
  }
  return res;
}
long long int f, T, t0, a1, p1, t1, a2, p2, t2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> f >> T >> t0;
  cin >> a1 >> t1 >> p1;
  cin >> a2 >> t2 >> p2;
  if (p1 < p2) {
    swap(p1, p2);
    swap(a1, a2);
    swap(t1, t2);
  }
  long long int ans = 1e16;
  for (long long int i = 0; i <= T; i++) {
    long long int cost = i * p1;
    long long int leftT = T - t1 * a1 * i;
    long long int leftF = f - i * a1;
    if (leftT <= 0) {
      if (leftF <= 0) {
        if (f * t1 <= T) {
          ans = min(ans, i * p1);
        }
      }
      break;
    }
    if (leftF <= 0) {
      if (f * t1 <= T) {
        ans = min(ans, i * p1);
      }
      break;
    }
    long long int low = 0, high = leftT / t2 + 5, mid, ret = mod;
    while (low <= high) {
      mid = (low + high) / 2;
      long long int curr = leftF - mid * a2;
      long long int currT = leftT - mid * a2 * t2;
      if (currT <= 0) {
        if (curr <= 0) {
          if (leftF * t2 <= leftT) {
            ret = min(ret, mid);
          }
        }
        high = mid - 1;
        continue;
      }
      if (curr <= 0) {
        ret = min(ret, mid);
        high = mid - 1;
        continue;
      }
      if (curr * t0 <= currT) {
        ret = min(ret, mid);
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (ret != mod) ans = min(cost + ret * p2, ans);
  }
  if (ans > 1e15) ans = -1;
  cout << ans;
  return 0;
}
