#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long need[100010], have[100010];
int check(long long mid) {
  long long i, j;
  long long lack = 0;
  for (i = 0; i < n; i++) {
    long long res = -1LL * have[i] + 1LL * need[i] * mid;
    if (res > 0) lack += res;
    if (lack > k) return 0;
  }
  if (lack <= k)
    return 1;
  else
    return 0;
}
int main() {
  long long i, j;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> need[i];
  }
  for (i = 0; i < n; i++) {
    cin >> have[i];
  }
  long long lack = 0;
  for (i = 0; i < n; i++) {
    if (have[i] - need[i] < 0) lack += need[i] - have[i];
  }
  if (lack > k)
    cout << 0;
  else {
    long long l = 1, r = 2e9;
    long long mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (r - l <= 1 && r - l >= 0) {
        if (check(r) == 1) {
          cout << r;
          break;
        } else if (check(l) == 1) {
          cout << l;
          break;
        } else {
          cout << 0;
          break;
        }
      } else {
        if (check(mid) == 1)
          l = mid;
        else
          r = mid - 1;
      }
    }
  }
}
