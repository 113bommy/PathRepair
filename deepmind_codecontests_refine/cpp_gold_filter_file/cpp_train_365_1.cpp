#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
struct T {
  int x, y;
} S[maxn];
static int N;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d%d", &S[i].x, &S[i].y);
  double L = S[1].x, R = S[2].x;
  if (S[3].y > S[2].y) swap(L, R);
  for (int i = 2; i < N; i++)
    if (S[i].y != S[i + 1].y) {
      double tx = S[i].x;
      if (S[i].x != S[i + 1].x)
        tx = double(S[2].y - S[i].y) / (S[i + 1].y - S[i].y) *
                 (S[i + 1].x - S[i].x) +
             S[i].x;
      if (S[i + 1].y > S[i].y) {
        if (L < tx) L = tx;
      } else if (R > tx)
        R = tx;
    } else if ((double)(S[1].x - S[2].x) * (S[i].x - S[i + 1].x) > 0)
      L = R + 1;
  if (L > R + 1E-10)
    printf("0\n");
  else
    printf("%d\n", int(R + 1E-10 + 10000) - int(L - 1E-10 + 10000));
  return 0;
}
