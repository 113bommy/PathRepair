#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18 + 7;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
inline long long read() {
  bool f = 0;
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n;
int a[maxn];
int main() {
  int t = read();
  while (t--) {
    n = read();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      if (i == 1) continue;
      if (a[i] >= a[i - 1]) continue;
      int x = a[i - 1] - a[i];
      int cnt = 0;
      while (x) {
        cnt++;
        x /= 2;
      }
      ans = max(ans, cnt);
      a[i] = a[i - 1];
    }
    cout << ans << endl;
  }
}
