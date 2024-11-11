#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
long long a[10005];
long long row, col;
int k;
vector<long long> vec[10005];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qmul(long long a, long long b) {
  long long ret = 0;
  while (b) {
    if (b & 1) {
      ret = ret + a;
      if (ret > INF) return -1;
    }
    a = a + a;
    b >>= 1;
    if (b && a > INF) return -1;
  }
  return ret;
}
long long lcm(long long a, long long b) { return qmul(a / gcd(a, b), b); }
int pri[10005], tot;
bool check[10005];
vector<int> jump;
void init() {
  for (int i = 2; i <= 10000; i++) {
    if (!check[i]) pri[tot++] = i, jump.push_back(i);
    for (int j = i + i; j <= 10000; j += i) check[j] = true;
  }
  int ans = tot;
  for (int i = 0; i < tot; i++) {
    int st = pri[i] * pri[i];
    while (st <= 10000) {
      ans++;
      jump.push_back(st);
      st *= pri[i];
    }
  }
  sort(jump.begin(), jump.end());
}
long long r[10005], m[10005];
long long ex_gcd(long long a, long long &x, long long b, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long ans = ex_gcd(b, x, a % b, y);
  long long t = x;
  x = y, y = t - (a / b) * y;
  return ans;
}
long long mod_line(int n, long long &t) {
  long long rr = r[0], x, y;
  t = m[0];
  for (int i = 1; i < n; i++) {
    if (rr > INF) return -1;
    long long del = r[i] - rr;
    long long g = ex_gcd(t, x, m[i], y);
    if (del % g != 0) return -1;
    long long Mod = m[i] / g;
    x = (((x * del / g) % Mod) + Mod) % Mod;
    rr = rr + t * x;
    t = t * m[i] / g;
    rr %= t;
  }
  return rr;
}
int main() {
  init();
  scanf("%I64d%I64d%d", &row, &col, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%I64d", &a[i]);
  }
  bool flag = true;
  for (int i = 0; i < jump.size(); i++) {
    if (!flag) break;
    int fac = jump[i];
    if (fac > k) break;
    for (int j = 1; j <= k; j++) {
      if (a[j] % fac == 0) {
        if (j > fac && a[j - fac] % fac != 0) flag = false;
      } else {
        if (j > fac && a[j - fac] % fac == 0) flag = false;
      }
    }
  }
  long long x = 1;
  for (int i = 1; i <= k; i++) {
    if (!flag) break;
    x = lcm(x, a[i]);
    if (x < 0 || x > row) flag = false;
  }
  long long y = 0;
  for (int i = 0; i < k; i++) {
    m[i] = a[i + 1];
    r[i] = (k - i - 1) % m[i];
  }
  long long t;
  y = mod_line(k, t);
  while (y >= 0 && y - k + 1 <= 0) y += t;
  if (y < 0 || y > col) flag = false;
  if (flag)
    for (long long i = y - k + 1, p = 1; i <= y; i++, p++)
      if (gcd(i, x) != a[p]) flag = false;
  printf("%s\n", flag ? "YES" : "NO");
  return 0;
}
