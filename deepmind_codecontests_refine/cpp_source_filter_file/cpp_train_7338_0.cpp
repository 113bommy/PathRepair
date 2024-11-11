#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y) {
  x %= 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i) (res *= i) %= 1000000007;
  return res;
}
bool isprime(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = '1' + s;
  s = s + '1';
  int ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    if (s[j] != '.') {
      ++j;
      continue;
    }
    if (s[j] == '.') i = j;
    while (j < n && s[j] == '.') ++j;
    ans += (j - i - 1);
  }
  const int inf = int(4e5);
  while (m--) {
    int x;
    char ch;
    cin >> x >> ch;
    if ((s[x] == '.' && ch == '.') || (s[x] != '.' && ch != '.')) {
      cout << ans << '\n';
    } else {
      int get = 0;
      if (s[x] == '.' && ch != '.') {
        if (s[x + 1] == '.') --get;
        if (s[x - 1] == '.') --get;
        ans += get;
      } else {
        if (s[x + 1] == '.') ++get;
        if (s[x - 1] == '.') ++get;
        ans += get;
      }
      cout << ans << '\n';
      s[x] = ch;
    }
  }
  return 0;
}
