#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int maxn = 1e5 + 100;
const long double PI = acos(-1.0);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
int n, m;
char s[maxn];
int main() {
  while (cin >> n >> m) {
    scanf("%s", s);
    m++;
    int cun = 0, l = -1, r;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cun++;
        if (l == -1) l = i;
      }
      if (cun == m) {
        r = i;
        break;
      }
    }
    int mid, p = inf, q = inf, minn = 0;
    for (int i = l; i <= r; i++) {
      if (s[i] == '0') {
        if (i - l <= r - i)
          p = r - i;
        else {
          q = i - l;
          break;
        }
      }
    }
    if (p > q)
      mid = q + l;
    else
      mid = r - p;
    minn = max(mid - l, r - mid);
    for (int j = r + 1; j < n; j++) {
      if (s[j] == '0') {
        l++;
        while (s[l] != '0') l++;
        p = inf;
        q = inf;
        for (int i = mid; i <= j; i++)
          if (s[i] == '0') {
            if (i - l <= j - i)
              p = j - i;
            else {
              q = i - l;
              break;
            }
          }
        if (p > q)
          mid = q + l;
        else
          mid = j - p;
        int gg = max(mid - l, j - mid);
        minn = min(gg, minn);
      }
    }
    cout << minn << endl;
  }
  return 0;
}
