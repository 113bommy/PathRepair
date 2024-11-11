#include <bits/stdc++.h>
using namespace std;
long long int mod(long long int x, long long int m) { return (x % m + m) % m; }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long int fast_exp(long long int base, long long int exp) {
  long long int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp /= 2;
  }
  return res % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1, r, n, a, d, c, b, x, y, sum, cnt, i, j, k, m, l, q, maxx,
                minn, temp, ans, flag, g, ts;
  long long int mod = 1000000007;
  char ch, chh;
  double dans;
  string str, ttr;
  cin >> t;
  for (ts = 1; ts <= t; ts++) {
    flag = 0;
    sum = 0;
    cnt = 0;
    ans = 0;
    k = 0;
    maxx = 0;
    minn = 0;
    a = 0;
    b = 0;
    temp = 0;
    cin >> n >> str;
    for (i = 0; i < (n) / 2; i++) {
      if (str[i] == '0') {
        flag = 1;
        ans = i;
        break;
      }
    }
    if (flag == 1) {
      cout << ans + 1 << " " << n << " ";
      cout << ans + 2 << " " << n;
    } else {
      flag = 0;
      for (i = ((n - 1) / 2) + 1; i < n; i++) {
        if (str[i] == '0') {
          flag = 1;
          ans = i;
          break;
        }
      }
      if (flag == 1) {
        cout << 1 << " " << ans + 1 << " ";
        cout << 1 << " " << ans;
      } else if (n % 2 == 1 && str[n / 2] == '0') {
        cout << "1 " << (n + 1) / 2 << " ";
        cout << (n + 1) / 2 << " " << n;
      } else {
        cout << "1 " << n - 1 << " ";
        cout << "2 " << n;
      }
    }
    cout << "\n";
  }
  return 0;
}
