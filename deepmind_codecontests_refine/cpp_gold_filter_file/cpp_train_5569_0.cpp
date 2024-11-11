#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000LL;
void Add(long long &a, long long b) {
  a += b;
  if (a >= inf) a = inf;
}
long long F[1005];
int Ans[1005];
int main() {
  int n;
  long long K;
  scanf("%d%I64d", &n, &K);
  F[0] = 1;
  for (int i = 0; i <= n - 1; i++)
    for (int j = i + 1; j <= i + 2; j++) Add(F[j], F[i]);
  for (int i = 1, j; i <= n; i = j + 1) {
    for (j = i; j <= n; j++)
      if (F[n - j] >= K) {
        for (int k = i; k <= j - 1; k++) Ans[k] = k + 1;
        Ans[j] = i;
        break;
      } else
        K -= F[n - j];
  }
  for (int i = 1; i <= n; i++) printf("%d ", Ans[i]);
  printf("\n");
}
