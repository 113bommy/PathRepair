#include <bits/stdc++.h>
using namespace std;
map<tuple<long long, long long, long long>, long long> book;
long long dp(long long l, long long r, long long dis, long long back) {
  back = min(back, r);
  back = max(back, l);
  if (book[make_tuple(r - l, dis, back - l)])
    return book[make_tuple(r - l, dis, back - l)];
  int mid = l + (r - l) / 2;
  if (mid - l > dis || (mid - l == dis && mid <= back)) {
    return book[make_tuple(r - l, dis, back - l)] =
               dp(l, mid, dis, back) + dp(mid, r, dis, back) + 1;
  }
  return book[make_tuple(r - l, dis, back - l)] = 0;
}
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  if (k == 1) {
    cout << 1 << endl;
    return 0;
  } else if (k == 2) {
    cout << n << endl;
    return 0;
  }
  k -= 2;
  long long x = 1, y = n + 1;
  while (x < y) {
    long long mid = x + (y - x) / 2;
    if (dp(1, n, mid, n) >= k)
      x = mid + 1;
    else
      y = mid;
  }
  long long anslen = x - 1;
  x = 1, y = n + 1;
  while (x < y) {
    long long mid = x + (y - x) / 2;
    if (dp(1, n, anslen, mid) >= k)
      y = mid;
    else
      x = mid + 1;
  }
  cout << x << endl;
  return 0;
}
