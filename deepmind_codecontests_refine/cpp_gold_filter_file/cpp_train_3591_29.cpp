#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j;
  long long N, M;
  scanf("%lld%lld", &N, &M);
  if (N == 1)
    printf("1\n");
  else {
    long long temp1 = N - M;
    long long temp2 = M - 1;
    if (temp1 > temp2)
      printf("%lld\n", M + 1);
    else
      printf("%lld\n", M - 1);
  }
  return 0;
}
