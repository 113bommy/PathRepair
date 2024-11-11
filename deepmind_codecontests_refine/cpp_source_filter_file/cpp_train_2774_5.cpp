#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, K;
  int i, j;
  long long int kind = 0, box = 0;
  long long int ma = 987654321987654321;
  scanf("%lld %lld", &N, &K);
  for (i = 0; i < K; i++) {
    long long int a;
    scanf("%lld", &a);
    if (N % a < ma) {
      kind = i + 1;
      box = N / a;
      ma = N % a;
    }
  }
  printf("%lld %lld", kind, box);
  return 0;
}
