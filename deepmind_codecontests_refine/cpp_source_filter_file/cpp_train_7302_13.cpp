#include <bits/stdc++.h>
using namespace std;
const int NB = 62;
int main() {
  int N;
  scanf("%d", &N);
  vector<int> val(N);
  vector<long long> mask(N);
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d %lld", &val[i], &mask[i]);
    sum += val[i];
  }
  if (sum < 0) {
    sum *= -1;
    for (int i = 0; i < N; ++i) {
      val[i] *= -1;
    }
  }
  long long s = 0;
  for (int i = 0; i < NB; ++i) {
    long long delta = 0;
    for (int j = 0; j < N; ++j) {
      if ((1LL << i) == mask[j]) {
        delta -= 2 * val[j];
      }
    }
    if (delta < 0) {
      sum += delta;
      for (int j = 0; j < N; ++j) {
        if ((1LL << i) & mask[j]) {
          val[j] *= -1;
        }
      }
      s ^= (1 << i);
    }
    for (int j = 0; j < N; ++j) {
      mask[j] &= ((1LL << NB) - 1) - (1LL << i);
    }
  }
  printf("%lld\n", s);
  return 0;
}
