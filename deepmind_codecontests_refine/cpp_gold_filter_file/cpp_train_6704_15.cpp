#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long n, s[65];
int num = 0;
void BinarySearch() {
  for (int k = 0; k < 63; k++) {
    long long left = 1, right = 3 * 1e9, m, ans;
    if (k >= 30) right = INF >> k;
    while (left <= right) {
      m = (left + right) >> 1;
      ans = ((1ll << k) - 1) * m * 2 + m * (m - 1);
      if (ans > n * 2)
        right = m - 1;
      else if (ans < n * 2)
        left = m + 1;
      else {
        if (m & 1) s[num++] = ((1ll << k)) * m;
        break;
      }
    }
  }
}
int main() {
  cin >> n;
  BinarySearch();
  sort(s, s + num);
  if (num == 0)
    printf("-1\n");
  else
    for (int i = 0; i < num; i++) printf("%lld\n", s[i]);
  return 0;
}
