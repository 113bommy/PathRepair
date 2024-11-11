#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
inline long long min(long long x, long long y, long long z) {
  return min(x, min(y, z));
}
inline long long max(long long x, long long y, long long z) {
  return max(x, max(y, z));
}
inline long long add(long long x, long long y) {
  return x + y >= 998244353 ? x + y - 998244353 : x + y;
}
inline long long add(long long x, long long y, long long z) {
  return add(add(x, y), z);
}
inline long long sub(long long x, long long y) {
  return x - y < 0 ? x - y + 998244353 : x - y;
}
inline long long mul(long long x, long long y) {
  return 1LL * x * y % 998244353;
}
inline long long mul(long long x, long long y, long long z) {
  return mul(mul(x, y), z);
}
long long ans;
void solve(vector<long long> a, vector<long long> b, vector<long long> c) {
  long long j = 0, k = 0;
  for (long long i = 0; i < (long long)a.size(); i++) {
    while (j < (long long)b.size() && a[i] > b[j]) j++;
    if (j == (long long)b.size()) return;
    while (k < (long long)c.size() && b[j] > c[k]) k++;
    if (k == 0) continue;
    long long R = (a[i] - b[j]) * (a[i] - b[j]) +
                  (a[i] - c[k - 1]) * (a[i] - c[k - 1]) +
                  (b[j] - c[k - 1]) * (b[j] - c[k - 1]);
    if (R < ans) ans = R;
  }
}
void work() {
  long long n, m, k;
  ans = 0x3f3f3f3f3f3f3f3f;
  cin >> n >> m >> k;
  vector<long long> a(n), b(m), c(k);
  for (long long i = 0; i < n; i++) a[i] = read();
  for (long long i = 0; i < m; i++) b[i] = read();
  for (long long i = 0; i < k; i++) c[i] = read();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  solve(a, b, c);
  solve(a, c, b);
  solve(b, a, c);
  solve(b, c, a);
  solve(c, a, b);
  solve(c, b, a);
  cout << ans << endl;
}
signed main() {
  long long T = read();
  while (T--) work();
  return 0;
}
