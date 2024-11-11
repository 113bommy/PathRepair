#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, m, i, s, j, k, c;
  {
    s = 0;
    cin >> k;
    string a;
    cin >> a;
    n = a.size();
    if (n % k) {
      s = 0;
      string ans = "1";
      for (i = 1; i < k; i++) ans = ans + '0';
      while (s < n) {
        cout << ans;
        s += k;
      }
    } else {
      string ans;
      long long f = 0;
      for (i = k - 1; i >= 0; i--) {
        if (a[i] != '9') {
          char ch = a[i];
          ch++;
          f = 1;
          ans = ans + ch;
          i--;
          break;
        }
        ans = ans + a[i];
      }
      if (!f) {
        n = n + k;
        s = 0;
        string ans = "1";
        for (i = 1; i < k; i++) ans = ans + '0';
        while (s < n) {
          cout << ans;
          s += k;
        }
      } else {
        for (i; i >= 0; i--) ans = ans + a[i];
        reverse(ans.begin(), ans.end());
        string ans1;
        for (i = 0; i < k; i++) ans1 += a[i];
        long long f = 0;
        for (i = 0; i < n; i++) {
          if (a[i] > ans1[i % k]) {
            f = 2;
            break;
          } else if (a[i] < ans1[i % k]) {
            f = 1;
            break;
          }
        }
        if (f == 1) {
          s = 0;
          while (s < n) {
            cout << ans1;
            s += k;
          }
        } else {
          s = 0;
          while (s < n) {
            cout << ans;
            s += k;
          }
        }
      }
    }
  }
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modInverse(long long a, long long m) { return power(a, m - 2, m); }
