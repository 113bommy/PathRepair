#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int N, M, K;
long double f[MAXN], Ans;
long double C(int x, int y) { return f[x] - f[y] - f[x - y]; }
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= 1e5; i++) f[i] = f[i - 1] + log(1.0 * i);
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++) {
      int z = N * (i + j) - i * j;
      if (z > K) continue;
      long double tmp = C(N, i) + C(N, j) + C(M - z, K - z) - C(M, K);
      Ans = min((long double)(1e99), Ans + exp(tmp));
    }
  printf("%.10f\n", (double)Ans);
}
