#include <bits/stdc++.h>
using namespace std;
bool pr[1000007];
long long fpow(long long x, long long y) {
  x = x % 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= 1000000007;
    y = y >> 1;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
long long inv(long long a, long long m = 1000000007) {
  long long c = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += c;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long res = 0;
  long long rows[n + 1], cols[n + 1];
  memset(rows, 0, sizeof(rows));
  memset(cols, 0, sizeof(cols));
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    rows[x] = 1;
    cols[y] = 1;
  }
  if (n % 2 && !cols[n / 2 + 1] && !rows[n / 2 + 1]) res++;
  for (int i = 2; i <= n / 2; i++) {
    if (!rows[i]) res++;
    if (!cols[i]) res++;
    if (!rows[n + 1 - i]) res++;
    if (!cols[n + 1 - i]) res++;
  }
  cout << res;
}
