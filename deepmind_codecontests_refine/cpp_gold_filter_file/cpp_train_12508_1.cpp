#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18 + 7;
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
const int N = 2e5 + 5;
int t;
vector<int> q;
int a[N];
int pos[N];
int book[N];
int ans[N];
int main() {
  int n, k;
  while (cin >> n >> k) {
    for (register int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      q.emplace_back(a[i]);
      pos[a[i]] = i;
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int op = 1;
    for (register int i = 1; i <= n; ++i) {
      int j = a[i];
      if (book[j])
        continue;
      else
        book[j] = 1;
      int idx = find(q.begin(), q.end(), j) - q.begin();
      int be = max(0, idx - k);
      int en = min(idx + k, (int)q.size() - 1);
      for (register int i = be; i <= en; ++i) {
        ans[pos[q[i]]] = op;
        book[q[i]] = 1;
      }
      q.erase(q.begin() + be, q.begin() + en + 1);
      if (op == 2)
        op = 1;
      else
        op = 2;
    }
    for (register int i = 1; i <= n; ++i) printf("%d", ans[i]);
    puts("");
  }
  return 0;
}
