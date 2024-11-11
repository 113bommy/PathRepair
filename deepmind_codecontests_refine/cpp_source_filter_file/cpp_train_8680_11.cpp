#include <bits/stdc++.h>
using namespace std;
int N, M, K, c[105][105], f[55][55][55][105];
void doit() {
  scanf("%d%d%d", &N, &M, &K), N /= 2;
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = !j ? 1 : min(100, c[i - 1][j] + c[i - 1][j - 1]);
  int ans = 0;
  for (int i = 1; i <= N; i++) f[i][1][i][1] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j < M && j <= N; j++)
      for (int k = 1; k <= i; k++)
        for (int l = 1, x; l <= K; l++)
          if (x = f[i][j][k][l]) {
            (ans += 1ll * x * (M - j)) %= 1000000007;
            for (int t = 1; i + t <= N; t++)
              if (l * c[t + k - 1][k - 1] <= K)
                (f[i + t][j + 1][t][l * c[t + k - 1][k - 1]] += x) %=
                    1000000007;
          }
  cout << ans << endl;
}
int main() {
  doit();
  return 0;
}
