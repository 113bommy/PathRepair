#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 9e18;
const int inf = 2147483647;
long long phi(long long n) {
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
long long qpow(long long a, long long b, long long mod) {
  long long r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
  }
  return r;
}
long long C(int n, int m) {
  if (m < n - m) m = n - m;
  long long ans = 1;
  for (int i = m + 1; i <= n; i++) ans *= i;
  for (int i = 1; i <= n - m; i++) ans /= i;
  return ans;
}
const int N = 1e6 + 5;
struct ok {
  int x, y;
  bool operator<(const ok &b) const { return x < b.x || (b.x == x && y < b.y); }
} a[3];
vector<int> x, y;
bool mp[1005][1005];
void work() {
  int mn = 1005, mx = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    mn = min(a[i].y, mn);
    mx = max(mx, a[i].y);
  }
  sort(a, a + 3);
  memset(mp, false, sizeof(mp));
  for (int i = mn; i <= mx; i++) {
    mp[a[1].x][i] = 1;
    x.push_back(a[1].x);
    y.push_back(i);
  }
  for (int i = a[0].x; i <= a[1].x; i++) {
    if (!mp[i][a[0].y]) {
      mp[i][a[0].y] = 1;
      x.push_back(i);
      y.push_back(a[0].y);
    }
  }
  for (int i = a[1].x; i <= a[2].x; i++) {
    if (!mp[i][a[2].y]) {
      mp[i][a[2].y] = 1;
      x.push_back(i);
      y.push_back(a[2].y);
    }
  }
  printf("%d\n", x.size());
  for (int i = 0; i < x.size(); i++) printf("%d %d\n", x[i], y[i]);
}
int main() {
  work();
  return 0;
}
