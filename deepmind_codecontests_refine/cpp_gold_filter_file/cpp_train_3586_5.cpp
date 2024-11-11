#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long check(long long mid) {
  long long s = 0;
  for (int i = 1; i <= n; i++) s += min(mid / i, m);
  return s;
}
int main() {
  cin >> n >> m >> k;
  long long lo = 0, hi = m * n, mid = (lo + hi) / 2;
  while (lo < mid) {
    (check(mid) < k ? lo : hi) = mid;
    mid = (lo + hi) / 2;
  }
  cout << hi << '\n';
}
