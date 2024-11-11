#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int N;
int num[maxn];
int maxBit(int n) {
  int res = -1;
  while (n) {
    n >>= 1;
    res++;
  }
  return res;
}
int ans[maxn];
int ansn;
bool judge(int bit, int n) {
  if (n == (1 << bit)) return true;
  return false;
}
int main() {
  bool found = 0;
  int And, start;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &num[i]);
  for (int i = maxBit(num[N - 1]); i >= 0; i--) {
    And = -1;
    for (int j = 0; j < N; j++) {
      if (num[j] & (1 << i)) {
        And &= num[j];
      }
    }
    if (And & (1 << i)) {
      found = 1;
      start = i;
      break;
    }
  }
  if (found) {
    ansn = 0;
    for (int i = 0; i < N; i++)
      if (num[i] & (1 << start)) ans[ansn++] = num[i];
    printf("%d\n", ansn);
    for (int i = 0; i < ansn - 1; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[ansn - 1]);
  } else {
    printf("%d\n", N);
    for (int i = 0; i < N - 1; i++) printf("%d ", num[i]);
    printf("%d\n", num[N - 1]);
  }
  return 0;
}
