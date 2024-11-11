#include <bits/stdc++.h>
using namespace std;
long long get(long long m) {
  long long ans = 0;
  for (long long i = 2; i * i * i <= m; i++) {
    ans += m / (i * i * i);
  }
  return ans;
}
int main() {
  long long m, n = -1;
  while (cin >> m) {
    long long l = 0, r = 100;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (get(mid) < m)
        l = mid + 1;
      else
        r = mid;
    }
    if (get(l) == m) n = l;
    cout << n << endl;
  }
}
