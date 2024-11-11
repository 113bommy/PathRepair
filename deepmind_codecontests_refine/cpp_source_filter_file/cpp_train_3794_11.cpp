#include <bits/stdc++.h>
using namespace std;
long long m, k;
long long C[63 + 1][63 + 1];
const long long linf = 1000000000000000000LL;
int bit_count(long long x) {
  int ans = 0;
  while (x) {
    x &= (x - 1);
    ans++;
  }
  return ans;
}
long long calculate_good(long long x) {
  long long Ans = 0, cnt = 0;
  for (int i = 63; i >= 0 && cnt <= k; i--) {
    if (x & (1ll << i)) {
      Ans += C[i][k - cnt];
      cnt++;
    }
  }
  if (bit_count(x) == k) Ans++;
  return Ans;
}
int main(int argc, char const *argv[]) {
  scanf("%lld %lld", &m, &k);
  memset(C, 0, sizeof C);
  C[0][0] = 1;
  for (int i = 1; i <= 63; ++i) {
    for (int j = 0; j <= i; j++) {
      C[i][j] = C[i - 1][j] + ((j) ? C[i - 1][j - 1] : 0);
    }
  }
  long long mid, res, l = 1, r = linf;
  while (l < r) {
    mid = l + (r - l) / 2;
    res = calculate_good(mid * 2) - calculate_good(mid);
    if (res >= m) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%I64\n", l);
  return 0;
}
