#include <bits/stdc++.h>
using namespace std;
const int SIZE = (int)1e6 + 77;
int A, B, C, D;
long long cSum[SIZE];
void solve() {
  for (int i = A; i <= B; i++) {
    cSum[i + B]++;
    cSum[i + C + 1]--;
  }
  for (int i = 1; i < SIZE; i++) {
    cSum[i] += cSum[i - 1];
  }
  for (int i = 1; i < SIZE; i++) {
    cSum[i] += cSum[i - 1];
  }
  long long ret = 0;
  for (int i = C; i <= D; i++) ret += cSum[SIZE - 1] - cSum[i];
  printf("%lld\n", ret);
}
int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);
  solve();
  return 0;
}
