#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1 << 18;
int N, K;
long long int IP[MaxN];
int main(void) {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 4; j++) {
      if (j) scanf(".");
      int Number;
      scanf("%d", &Number);
      IP[i] = (IP[i] << 8LL) + Number;
    }
  long long int Mask = 0LL;
  for (int i = 31; i >= 1; i--) {
    Mask |= 1LL << i;
    set<long long int> S;
    for (int j = 0; j < N; j++) S.insert(Mask & IP[j]);
    if (S.size() == K) {
      for (int j = 0; j < 4; j++) {
        if (j) printf(".");
        printf("%d", (Mask >> (8LL * (3LL - j))) & 255LL);
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
