#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, div = 2LL, cnt = 0;
  long long nOrg;
  cin >> N;
  nOrg = N;
  if (N == 1) {
    printf("1\n0\n");
    return 0;
  }
  long long res = 1LL;
  while (cnt < 2 && N > 1 && div * div <= nOrg) {
    if (N % div == 0) {
      cnt++;
      res *= div;
      N /= div;
    } else
      div++;
  }
  if (cnt >= 2 && res != nOrg) {
    printf("1\n%d\n", int(res));
  } else if (cnt == 1) {
    printf("1\n0\n");
  } else {
    printf("2\n");
  }
  return 0;
}
