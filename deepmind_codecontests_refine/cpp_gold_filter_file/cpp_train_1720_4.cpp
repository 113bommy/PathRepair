#include <bits/stdc++.h>
using namespace std;
long long N, res;
int main() {
  scanf("%I64d", &N);
  for (long long left = 1, right = 1e9, mid; left <= right;) {
    mid = (left + right) / 2;
    if (mid * (mid + 1) / 2 == N) {
      printf("%I64d", mid);
      exit(0);
    } else if (mid * (mid + 1) / 2 > N)
      right = mid - 1;
    else
      res = max(res, mid), left = mid + 1;
  }
  printf("%I64d", N - res * (res + 1) / 2);
}
