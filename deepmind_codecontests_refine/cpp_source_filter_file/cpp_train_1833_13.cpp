#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int N, M, D, X[(100005)], Y[(100005)], x[(100005)], y[(100005)], a, b, c, d,
    O[(100005)], S[(100005)];
void go(int *x, int *X, int a, int b) {
  (memset(S, 0, sizeof(S)));
  for (int i(0); i < D; i++) ++S[x[i]];
  for (int k(1); k < (100005); k++) S[k] += S[k - 1];
  for (int i(0); i < D; i++)
    O[i] &= (S[X[i] - 1] - (0 ? S[0 - 1] : 0)) - (x[i] < X[i]) == a;
  (memset(S, 0, sizeof(S)));
  for (int i(0); i < D; i++) ++S[X[i]];
  for (int k(1); k < (100005); k++) S[k] += S[k - 1];
  for (int i(0); i < D; i++)
    O[i] &=
        (S[(100005) - 1] - (x[i] + 1 ? S[x[i] + 1 - 1] : 0)) - (X[i] > x[i]) ==
        b;
}
int main(void) {
  scanf("%d%d%d", &D, &N, &M), fill(O, O + (100005), 1);
  for (int i(0); i < D; i++) scanf("%d%d%d%d", X + i, Y + i, x + i, y + i);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i(0); i < D; i++)
    if (y[i] > Y[i]) swap(y[i], Y[i]);
  for (int i(0); i < D; i++)
    if (x[i] > X[i]) swap(x[i], X[i]);
  go(x, X, a, b), go(y, Y, c, d);
  for (int i(0); i < N; i++)
    if (O[i]) return printf("%d\n", i + 1), 0;
  puts("-1");
  return 0;
}
