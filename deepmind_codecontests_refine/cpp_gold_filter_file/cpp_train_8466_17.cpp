#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], b[N];
long long check(long long x, int n, int c) {
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += x * a[i] / b[i] + 1;
    if (ans > c) ans = c + 1;
  }
  return ans;
}
int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    sum += a[i];
  }
  long long limit = 1000000000000000000LL;
  long long l, r;
  if (check(1, n, c) >= c)
    l = 1;
  else {
    long long head = 1, tail = limit / sum;
    while (head < tail - 1) {
      long long mid = head + tail >> 1;
      if (check(mid, n, c) >= c)
        tail = mid;
      else
        head = mid;
    }
    l = tail;
  }
  if (check(limit / sum, n, c) <= c)
    r = limit / sum;
  else {
    long long head = 1, tail = limit / sum;
    while (head < tail - 1) {
      long long mid = head + tail >> 1;
      if (check(mid, n, c) <= c)
        head = mid;
      else
        tail = mid;
    }
    r = head;
  }
  long long ans = 0;
  if (l <= r && check(l, n, c) == c && check(r, n, c) == c) ans = r - l + 1;
  cout << ans << endl;
  return 0;
}
