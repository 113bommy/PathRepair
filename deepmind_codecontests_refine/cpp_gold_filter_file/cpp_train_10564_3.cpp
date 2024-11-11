#include <bits/stdc++.h>
using namespace std;
int init[100010];
bool occurs[100010];
int T[100010], R[100010];
bool np[100010];
int main() {
  int cases;
  scanf("%d", &cases);
  for (int n = 0; n < cases; n++) {
    int M, K, idx = -1;
    scanf("%d %d", &M, &K);
    M -= 1;
    for (int i = 0; i < K; i++) occurs[i] = np[i] = false;
    for (int i = 0; i < K; i++) scanf("%d", &init[i]);
    for (int i = 0; i < M; i++) {
      scanf("%d %d", &T[i], &R[i]);
      if (idx == -1 && R[i] == 1) idx = i;
      if (T[i] == 0) continue;
      init[T[i] - 1] -= 1;
    }
    if (idx == -1) {
      int totu = 0;
      for (int i = 0; i < M; i++)
        if (T[i] == 0) totu += 1;
      for (int i = 0; i < K; i++) {
        if (init[i] - totu <= 0)
          printf("Y");
        else
          printf("N");
      }
      printf("\n");
      continue;
    }
    int totu = 0;
    for (int i = 0; i < idx; i++)
      if (T[i] == 0) totu += 1;
    for (int i = idx; i < M; i++)
      if (T[i] != 0) occurs[T[i] - 1] = true;
    int minkill = 100010;
    for (int i = 0; i < K; i++)
      if (occurs[i] == false && init[i] <= totu) {
        np[i] = true;
        minkill = min(minkill, init[i]);
      }
    assert(minkill != 100010);
    totu -= minkill;
    for (int i = idx; i < M; i++)
      if (T[i] == 0) totu += 1;
    for (int i = 0; i < K; i++)
      if (init[i] <= totu) np[i] = true;
    for (int i = 0; i < K; i++) {
      if (np[i])
        printf("Y");
      else
        printf("N");
    }
    printf("\n");
  }
  return 0;
}
