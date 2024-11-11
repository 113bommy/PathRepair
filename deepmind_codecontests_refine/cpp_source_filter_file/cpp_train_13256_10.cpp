#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 10, maxNum = 100 + 10, maxL = 3000 + 10, P = 1000000007,
          INF = 2147483647;
int N, L;
int f[maxL][maxN];
struct fence {
  int A, B, Num;
} F[maxN];
void setIO(string name) {
  string in = name + ".in";
  string out = name + ".out";
  freopen(in.c_str(), "r", stdin);
  freopen(out.c_str(), "w", stdout);
}
int main() {
  scanf("%d %d", &N, &L);
  memset(f, 0, sizeof(f));
  int a, b;
  int cnt = -1;
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &a, &b), ++cnt;
    F[cnt].A = a;
    F[cnt].B = b;
    F[cnt].Num = i;
    if (a != b) {
      ++cnt;
      F[cnt].A = b;
      F[cnt].B = a;
      F[cnt].Num = i;
    }
  }
  N = cnt + 1;
  for (int i = 0; i < N; ++i) f[F[i].A][i] = 1;
  for (int i = 1; i <= L; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        if (F[j].Num != F[k].Num && F[k].A < i && F[j].B == F[k].A)
          f[i][k] = (f[i][k] + f[i - F[k].A][j]) % P;
  int ans = 0;
  for (int i = 0; i < N; ++i) ans = (ans + f[L][i]) % P;
  printf("%d\n", ans);
  return 0;
}
