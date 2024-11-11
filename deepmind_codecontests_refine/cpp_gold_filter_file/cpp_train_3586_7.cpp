#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
  cin >> n >> m >> k;
  long long lo = 1, hi = (n * m), mid = (lo + hi) / 2;
  while (lo < hi) {
    mid = (lo + hi + 1) >> 1;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) cnt += min((mid - 1) / i, m);
    if (cnt >= k)
      hi = mid - 1;
    else
      lo = mid;
  }
  cout << lo << '\n';
  return 0;
}
