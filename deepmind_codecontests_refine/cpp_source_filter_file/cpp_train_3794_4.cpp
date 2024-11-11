#include <bits/stdc++.h>
using namespace std;
long long C[65][65];
long long m;
long long k;
long long Count(long long x, int k) {
  long long ans = (__builtin_popcount(x) == k), cnt = 0;
  for (int i = 63; i >= 0 && k >= 0; i--) {
    if ((x >> i) & 1) {
      ans += C[i][k--];
    }
  }
  return ans;
}
int main() {
  cin >> m >> k;
  C[0][0] = 1;
  for (int i = 1; i <= 64; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        C[i][j] = C[i - 1][j];
      } else {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      }
    }
  }
  long long l = 1;
  long long r = 1e18;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (Count(2 * mid, k) - Count(mid, k) < m) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l;
}
