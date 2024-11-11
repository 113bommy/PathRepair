#include <bits/stdc++.h>
using namespace std;
inline int Get_Int() {
  int Num = 0, Flag = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') Flag = -Flag;
  } while (ch < '0' || ch > '9');
  do {
    Num = Num * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return Num * Flag;
}
int N, M;
int A[1005];
double Ans;
double F[1005][1005];
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) A[i] = Get_Int();
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) F[i][j] = (int)(A[i] > A[j]);
  while (M--) {
    int x = Get_Int(), y = Get_Int();
    for (int i = 1; i <= N; ++i) {
      F[x][i] = F[y][i] = 0.5 * F[x][i] + 0.5 * F[y][i];
      F[i][x] = F[i][y] = 0.5 * F[i][x] + 0.5 * F[i][y];
    }
    F[x][y] = F[y][x] = 0.5;
  }
  for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j) Ans += F[i][j];
  printf("%.8lf\n", Ans);
  return 0;
}
