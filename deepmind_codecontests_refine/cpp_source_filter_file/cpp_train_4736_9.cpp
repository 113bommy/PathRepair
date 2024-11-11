#include <bits/stdc++.h>
using namespace std;
const int MAXC = 400;
int N, K, C;
int holiday[MAXC];
int main() {
  scanf("%d %d", &N, &K);
  scanf("%d", &C);
  for (int i = 0; i < (int)(C); ++i) scanf("%d", &holiday[i]);
  int pLimit = 0, ans = 0;
  for (int i = 0; i < (int)(C); ++i) {
    while (pLimit + K < holiday[i]) {
      ans++;
      pLimit += K;
    }
    pLimit = holiday[i];
  }
  while (pLimit < N) pLimit += K, ans++;
  printf("%d\n", ans + C);
  return 0;
}
