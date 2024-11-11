#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535;
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
int g[110][110];
int F[111][111][22], P[111][111][22];
int N, M, K;
void PRINT(int n, int ret, int k) {
  k = (k + K) % K;
  if (n == N) {
    cout << ret << endl;
  } else {
    PRINT(n + 1, P[n][ret][k], k - g[n][ret]);
    if (P[n][ret][k] - 1 == ret) cout << "L";
    if (P[n][ret][k] + 1 == ret) cout << "R";
  }
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char t;
      cin >> t;
      g[i][j] = t - '0';
    }
  }
  K++;
  memset(F, -1, sizeof(F));
  for (int i = 1; i <= M; i++) F[N][i][g[N][i] % K] = g[N][i];
  for (int i = N; i > 1; i--)
    for (int j = 1; j <= M; j++)
      for (int k = 0; k < K; k++)
        if (F[i][j][k] >= 0) {
          if (j > 1) {
            int temp = (k + g[i - 1][j - 1]) % K;
            if (F[i][j][k] + g[i - 1][j - 1] > F[i - 1][j - 1][temp]) {
              F[i - 1][j - 1][temp] = F[i][j][k] + g[i - 1][j - 1];
              P[i - 1][j - 1][temp] = j;
            }
          }
          if (j < M) {
            int temp = (k + g[i - 1][j + 1]) % K;
            if (F[i][j][k] + g[i - 1][j + 1] > F[i - 1][j + 1][temp]) {
              F[i - 1][j + 1][temp] = F[i][j][k] + g[i - 1][j + 1];
              P[i - 1][j + 1][temp] = j;
            }
          }
        }
  int ret = 0;
  for (int i = 1; i <= M; i++) {
    if (F[1][i][0] > F[1][ret][0]) ret = i;
  }
  cout << F[1][ret][0] << endl;
  if (ret == 0) return 0;
  PRINT(1, ret, 0);
  cout << endl;
  return 0;
}
