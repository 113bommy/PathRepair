#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000 + 7;
const double esp = 1e-13;
long long nhan(long long x, long long y, long long m) {
  long long ans = 0;
  while (y) {
    if (y % 2) ans = (ans + x) % m;
    x = x * 2 % m;
    y /= 2;
  }
  return ans;
}
long long power(long long a, long long n, long long m) {
  unsigned long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a % m;
    a = a * a % m;
    n /= 2;
  }
  return ans;
}
bool check(long long n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  long long p[3] = {3, 5, 7};
  long long a, d;
  int r, s;
  d = n - 1;
  s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (long long i = 0; i <= 2; i++) {
    if (n == p[i]) return true;
    if (n % p[i] == 0) return false;
    a = power(p[i], d, n);
    if (a != 1) {
      for (r = 0; r < s && a != n - 1; r++) a = a * a % n;
      if (r == s) return false;
    }
  }
  return true;
}
long long phi(long long n) {
  long long ans = n;
  long long n2 = (long long)sqrt(n);
  for (long long i = 2; i <= n2; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
bool ok;
string s;
int n, a[100 + 100], b[20][20], ans, tdhang, tdcot, hang, cot, dem;
vector<pair<int, int> > res;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  srand(time(0));
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> s;
    for (long long j = 0; j <= 11; j++) a[j + 1] = (s[j] == 'X');
    ans = 0;
    res.clear();
    for (long long hang = 1; hang <= 12; hang++)
      if (12 % hang == 0) {
        cot = 12 / hang;
        memset(b, 0, sizeof(b));
        tdhang = 1;
        tdcot = 1;
        for (long long j = 1; j <= 12; j++) {
          b[tdhang][tdcot] = a[j];
          if (tdcot == cot)
            tdhang++, tdcot = 1;
          else
            tdcot++;
        }
        ok = false;
        for (long long kcot = 1; kcot <= cot; kcot++)
          if (b[1][kcot]) {
            dem = 0;
            for (long long khang = 2; khang <= hang; khang++)
              if (b[khang][kcot] == b[khang - 1][kcot]) dem++;
            if (dem == hang - 1) ok = true;
          }
        if (ok) res.push_back(pair<int, int>(hang, cot));
      }
    cout << res.size() << " ";
    for (typeof((res).begin()) it = (res).begin(); it != (res).end(); it++)
      cout << it->first << "x" << it->second << " ";
    cout << "\n";
  }
}
