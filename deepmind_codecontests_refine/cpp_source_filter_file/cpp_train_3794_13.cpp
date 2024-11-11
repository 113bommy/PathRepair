#include <bits/stdc++.h>
using namespace std;
long long m;
int k;
long long C[100][100];
void get_C() {
  for (int i = 0; i <= 64; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
long long test(long long x) {
  long long ret = 0, cnt = 0;
  for (long long t = 1LL << 62, p = 62; t; t >>= 1, --p) {
    if (x & t) ret += C[p][k - cnt], ++cnt;
    if (cnt > k) break;
  }
  return ret;
}
int main() {
  get_C();
  cin >> m >> k;
  long long ll = 0, rr = 1000000000000000010LL;
  while (ll < rr) {
    long long mm = (ll + rr) >> 1;
    if (test(mm << 1) - test(mm) < m)
      ll = mm + 1;
    else if (test(mm << 1) - test(mm) > m)
      rr = mm - 1;
    else
      break;
  }
  printf("%I64d\n", (ll + rr) >> 1);
  return 0;
}
