#include <bits/stdc++.h>
using namespace std;
int D[100][100];
int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", D[i] + j);
    }
  }
  if (M > 10) {
    for (int i = 0; i < 100; i++) {
      for (int j = i; j < 100; j++) {
        swap(D[i][j], D[j][i]);
      }
    }
    swap(N, M);
  }
  if (N > 10) {
    int mn = K + 1;
    for (int t = 0; t < N; t++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        int cnt = 0;
        for (int i = 0; i < M; i++) {
          if (D[j][i] != D[t][i]) cnt++;
        }
        if (cnt > M / 2)
          sum += M - cnt;
        else
          sum += cnt;
      }
      mn = min(sum, mn);
    }
    if (mn > K)
      printf("-1");
    else
      printf("%d", mn);
  } else {
    int tg[10] = {0}, mn = K + 1;
    for (int i = 0; i < 1 << M; i++) {
      for (int j = 0; j < M; j++) {
        if (i & (1 << j))
          tg[j] = 1;
        else
          tg[j] = 0;
      }
      int sum = 0;
      for (int j = 0; j < N; j++) {
        int cnt = 0;
        for (int i = 0; i < M; i++) {
          if (D[j][i] != tg[i]) cnt++;
        }
        if (cnt > M / 2)
          sum += M - cnt;
        else
          sum += cnt;
      }
      mn = min(sum, mn);
    }
    if (mn > K)
      printf("-1");
    else
      printf("%d", mn);
  }
}
