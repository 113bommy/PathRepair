#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k;
long long find(int x, int y) {
  if (x > n || x < 1) return 0;
  int p = (2 * n - 2) * m, left = k % p;
  long long times = k / p, ans = (x == 1 || x == n) ? times : (times * 2);
  if (left <= p / 2)
    ans += left >= ((x - 1) * m + y);
  else {
    if (x != n) ans++;
    left -= p / 2;
    ans += left >= ((n - x) * m + y);
  }
  return ans;
}
int main() {
  int x, y;
  scanf("%d%d%lld%d%d", &n, &m, &k, &x, &y);
  if (n == 1) {
    long long times = k / m;
    int left = k % m;
    printf("%lld %lld %lld\n", times + (left > 0), times, times + (x <= left));
  } else
    printf("%lld %lld %lld\n", max(max(find(2, 1), find(n - 1, 1)), find(1, 1)),
           find(n, m), find(x, y));
}
