#include <bits/stdc++.h>
using namespace std;
long long s;
bool check(long long x) {
  long long tmp = x, sum = 0;
  while (tmp > 0) {
    sum += (tmp % 10);
    tmp /= 10;
  }
  if (x - sum >= s) {
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, n;
  cin >> n >> s;
  long long diff = 10 - 1;
  long long lo = 10, hi = n, mid;
  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  if (check(lo)) {
    cout << n - lo + 1;
  } else {
    cout << 0;
  }
  return 0;
}
