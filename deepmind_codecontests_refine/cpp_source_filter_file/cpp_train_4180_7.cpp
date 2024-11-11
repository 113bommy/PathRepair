#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double tiaohe = 0.57721566490153286060651209;
long long oula(long long x) {
  long long res = x;
  for (register int i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
long long quickmod(long long a, long long n, long long m) {
  long long s = 1;
  while (n) {
    if (n & 1) {
      s = s * a % m;
    }
    a = (a * a) % m;
    n = n / 2;
  }
  return s;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void ex_gcd(long long a, long long b, long long &x, long long &y,
            long long &d) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    ex_gcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
long long inv(long long t, long long p) {
  long long d, x, y;
  ex_gcd(t, p, x, y, d);
  return d == 1 ? (x % p + p) % p : -1;
}
bool isPrime(long long x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
double eqa = (1 + sqrt(5.0)) / 2.0;
const int N = 2e5 + 5;
int ans[3][N];
int ju[] = {26 * 26, 26, 1};
void ask(int k, int n) {
  printf("? ");
  for (register int i = 1; i <= n; ++i) {
    int pos = ceil(i * 1.0 / ju[k]);
    printf("%c", 'a' + (pos - 1));
  }
  cout << endl;
}
void solve(string s, int n) {
  if (n != 0) {
    for (register int i = 0; i <= N - 1; ++i) ans[n][i] = ans[n - 1][i];
  }
  for (register int i = 0; i <= (int)s.size() - 1; ++i)
    ans[n][i] += ju[n] * (s[i] - 'a');
}
int main() {
  string s, t;
  cin >> t;
  for (register int i = 0; i <= 2; ++i) {
    ask(i, (int)t.size());
    cin >> s;
    solve(s, i);
  }
  printf("! ");
  string res = t;
  for (register int i = 0; i <= (int)t.size() - 1; ++i) res[ans[2][i]] = t[i];
  cout << res << endl;
  return 0;
}
