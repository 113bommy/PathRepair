#include <bits/stdc++.h>
using namespace std;
int A[100005], X[100005];
int main() {
  int N;
  scanf("%d", &N);
  int ans = 0;
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  X[N] = N;
  for (int i = N - 1; i >= 1; i--) {
    if (A[i] >= A[X[i + 1]])
      X[i] = X[i + 1];
    else
      X[i] = i;
  }
  int prev_max = 0, prev_prev_max = 0;
  for (int i = 1; i <= N; i++) {
    if (X[i] == i) {
      if (A[i] >= prev_max) ans++;
      prev_prev_max = max(prev_prev_max, A[i]);
      prev_max = prev_prev_max;
    } else
      prev_prev_max = max(prev_prev_max, A[i]);
  }
  printf("%d\n", ans);
  return 0;
}
