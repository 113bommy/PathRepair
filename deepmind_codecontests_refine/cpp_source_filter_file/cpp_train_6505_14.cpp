#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 0.0000000001;
const int N = 300000 + 10;
const long long mod = 1e9 + 7;
long long b[N];
long long a[N];
int n, m;
int check(long long x) {
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) a[i] = b[i];
  long long ans = 0;
  int pos = 1;
  long long xx = x;
  if (x < n + 1) return 0;
  int t = 0;
  while (pos <= n) {
    x = xx;
    t++;
    x = x - pos;
    while (x && pos <= n) {
      if (x >= a[pos]) {
        x = x - a[pos];
        a[pos] = 0;
        pos++;
        if (x == 0) break;
        x--;
      } else {
        a[pos] = a[pos] - x;
        x = 0;
      }
    }
    if (t > m) return 0;
  }
  return 1;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    long long maxx = 0;
    for (int i = 1; i <= n; i++) {
      long long x;
      scanf("%I64d", &x);
      b[i] = x;
    }
    for (int i = n; i >= 1; i--) {
      if (a[i]) {
        n = i;
        break;
      }
    }
    long long mid;
    long long ans = 0;
    long long low = 0;
    long long high = 1000;
    while (low <= high) {
      mid = (low + high) >> 1;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << ans << endl;
  }
}
