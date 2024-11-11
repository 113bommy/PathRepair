#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int v[N], cu[N], cnt[N], pre[N], n;
bool check(int x, int len) {
  for (int i = 1; i < N; i++) {
    cu[i] = cnt[i];
  }
  if (x < len || x > (n - len)) return 0;
  if (x == (n + 1) / 2) {
    for (int i = x + 1; i <= n - len; i++) {
      cu[v[i]] -= 2;
      if (cu[v[i]] < 0) {
        return 0;
      }
    }
  } else if (x < (n + 1) / 2) {
    for (int i = x + 1; i <= n - x; i++) {
      if (v[i] != v[n - i + 1]) {
        return 0;
      }
      cu[v[i]]--;
      if (cu[v[i]] < 0) {
        return 0;
      }
    }
    for (int i = n - x + 1; i <= n; i++) {
      cu[v[i]] -= 2;
      if (cu[v[i]] < 0) {
        return 0;
      }
    }
  } else {
    for (int i = x + 1; i <= n - len; i++) {
      cu[v[i]] -= 2;
      if (cu[v[i]] < 0) {
        return 0;
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int is_OK = 0;
  cin >> n;
  is_OK -= (n % 2);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    cnt[v[i]]++;
  }
  for (int i = 1; i < N; i++) {
    is_OK += (cnt[i] % 2);
  }
  if (is_OK) {
    return cout << 0, 0;
  }
  pre[0] = 1;
  for (int i = 1; i <= n; i++) {
    pre[i] = (pre[i - 1] & (v[i] == v[n - i + 1]));
  }
  if (pre[n] == 1) {
    return cout << ((1ll) * n * (n + 1) / 2), 0;
  }
  long long L = 1, R = n, len;
  for (len = n; len >= 0; len--) {
    if (pre[len]) {
      for (int i = 1; i <= len; i++) {
        cnt[v[i]] -= 2;
      }
      int d = len + 1, up = n - len;
      while (up - d > 1) {
        int mid = (up + d) >> 1;
        if (check(mid, len)) {
          up = mid;
        } else {
          d = mid;
        }
      }
      if (check(d, len)) {
        up = d;
      }
      L = up;
      reverse(v + 1, v + n + 1);
      d = len + 1, up = n - len;
      while (up - d > 1) {
        int mid = (up + d) >> 1;
        if (check(mid, len)) {
          up = mid;
        } else {
          d = mid;
        }
      }
      if (check(d, len)) {
        up = d;
      }
      R = up;
      break;
    }
  }
  R = n - R + 1;
  long long ans =
      (len * len) + (n - len - L + 1) * (len + 1) + (R - len) * (len + 1);
  cout << --ans << "\n";
  return 0;
}
