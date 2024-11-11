#include <bits/stdc++.h>
using namespace ::std;
const int Nmax = 300000 + 10;
int a[Nmax];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &a[i]);
  }
  sort(a, a + N);
  long long sum = 0;
  for (int i = 0; i < N - 1; i++) {
    sum += a[i] * (i + 2);
  }
  sum += a[N - 1] * N;
  printf("%I64d\n", sum);
}
