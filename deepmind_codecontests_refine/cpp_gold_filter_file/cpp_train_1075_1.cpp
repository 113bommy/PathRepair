#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int ar[MAXN];
int N;
int get(int k) {
  int r = 1;
  while (k + (1 << r) <= N) {
    ++r;
  }
  --r;
  return k + (1 << r);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
  }
  long long sum = 0;
  for (int i = 1; i < N; ++i) {
    sum += ar[i];
    ar[get(i)] += ar[i];
    printf("%I64d\n", sum);
  }
  return 0;
}
