#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 1e5 + 10;
int add(int x, int y) {
  x += y;
  if (x >= 1000000007LL) x -= 1000000007LL;
  return x;
}
int mul(int x, int y) {
  x = (1LL * x * y) % 1000000007LL;
  return x;
}
int p(int x, int n) {
  if (n == 0 || x == 1) {
    return 1;
  } else if (n == 1) {
    return x;
  } else if (n % 2 == 0) {
    return p(mul(x, x), n / 2);
  }
  return mul(x, p(mul(x, x), n / 2));
}
int C(int n, int r) {
  int ans = 1, j = r;
  for (int i = 0; i < j; i++) {
    ans = mul(ans, n);
    ans = mul(ans, p(r, 1000000007LL - 2));
    n--;
    r--;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    int n, m, r;
    cin >> n >> m;
    vector<int> a(n + 2, 0);
    for (int i = 0; i < m; i++) {
      cin >> r;
      a[r] = 1;
    }
    int s = 0, e = 0, c = 0, ans = 1, k = n - m;
    if (k == 0) {
      cout << 1;
      return 0;
    }
    if (k == 1) {
      cout << 1;
      return 0;
    }
    a[0] = 1;
    a[n + 1] = 1;
    for (int i = 0; i < n + 2; i++) {
      if (a[i] == 1) {
        if (c > 0) {
          if (s == 0 || i == n + 1) {
            ans = mul(ans, C(k, c));
            k = k - c;
            c = 0;
          } else {
            ans = mul(mul(ans, C(k, c)), p(2, c - 1));
            k = k - c;
            c = 0;
          }
        }
        s = i;
      } else {
        c++;
      }
    }
    cout << ans;
  }
  return 0;
}
