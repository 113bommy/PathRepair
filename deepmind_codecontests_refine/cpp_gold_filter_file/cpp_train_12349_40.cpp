#include <bits/stdc++.h>
using namespace std;
void Get_Val(int &Ret) {
  Ret = 0;
  char ch;
  while (ch = getchar(), ch > '9' || ch < '0')
    ;
  do {
    (Ret *= 10) += ch - '0';
  } while (ch = getchar(), ch >= '0' && ch <= '9');
}
const int Max_N(55);
const int Max_R(5050);
int N, R, F[Max_N], S[Max_N], P[Max_N], PreS[Max_N];
void init() {
  Get_Val(N), Get_Val(R);
  for (int i = 1; i <= N; ++i)
    scanf("%d%d%d", F + i, S + i, P + i), PreS[i] = PreS[i - 1] + S[i];
}
long double G[Max_N][Max_R];
void work() {
  long double l(0.0), r(1000000000.0), mid, F00;
  for (int cnt = 0; cnt <= 100; ++cnt) {
    mid = (l + r) / 2.0;
    for (int t = 0; t <= PreS[N]; ++t)
      if (t <= R)
        G[N][t] = 0.0;
      else
        G[N][t] = mid;
    for (int i = N - 1; i >= 1; --i) {
      double p = P[i + 1] / 100.0;
      for (int t = 0; t <= PreS[i + 1]; ++t) {
        G[i][t] = mid;
        if (t <= R)
          G[i][t] =
              min(G[i][t], p * (G[i + 1][t + F[i + 1]] + F[i + 1]) +
                               (1.0 - p) * (G[i + 1][t + S[i + 1]] + S[i + 1]));
      }
    }
    F00 = P[1] / 100.0 * (G[1][F[1]] + F[1]) +
          (1.0 - P[1] / 100.0) * (G[1][S[1]] + S[1]);
    if (mid < F00)
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf", static_cast<double>(l));
}
int main() {
  init();
  work();
  return 0;
}
