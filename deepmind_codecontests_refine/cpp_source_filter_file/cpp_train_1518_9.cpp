#include <bits/stdc++.h>
using namespace std;
int N, T, K;
int a[200333];
int lo[200333], hi[200333];
int mid[200333];
int main() {
  scanf("%d%d%d", &N, &T, &K);
  for (int i = 1; i <= T; i++) scanf("%d", &a[i]);
  for (int t = 1; t < T; t++) hi[t] = a[t] - 1;
  for (int t = 1; t < T; t++) lo[t] = max(a[t] - a[t + 1], 0);
  hi[T] = lo[T] = a[T];
  int hiSum = 0;
  for (int t = 1; t <= T; t++) hiSum += hi[t];
  int loSum = 0;
  for (int t = 1; t <= T; t++) loSum += lo[t];
  bool possible = hiSum <= K && K <= loSum;
  if (!possible) {
    puts("-1");
    exit(0);
  }
  for (int t = 1; t <= T; t++) {
    mid[t] = lo[t];
    K -= lo[t];
  }
  for (int t = 1; K; t++) {
    int val = min(K, hi[t] - mid[t]);
    K -= val;
    mid[t] += val;
  }
  printf("%d\n", N);
  for (int v = 2; v <= 1 + a[1]; v++) printf("%d %d\n", 1, v);
  int uStart = 2;
  for (int t = 1; t < T; t++) {
    int u = uStart;
    int upCnt = a[t] - mid[t] - 1;
    for (int v = uStart + a[t]; v < uStart + a[t] + a[t + 1]; v++) {
      printf("%d %d\n", u, v);
      if (upCnt) {
        upCnt--;
        u++;
      }
    }
    uStart = uStart + a[t];
  }
  return 0;
}
