#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
long long m;
long long check(long long x) {
  long long sum = 0;
  for (long long k = 2; k * k * k <= x; k++) {
    sum += (x / (k * k * k));
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> m;
  long long l, r, mid;
  l = 0;
  r = 1e15;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid) >= m) {
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (check(l) == m)
    cout << l << endl;
  else if (check(l + 1) == m)
    cout << l + 1 << endl;
  else
    cout << -1 << endl;
  return 0;
}
