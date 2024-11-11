#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int C[100005], R[100005], W;
int gc(int a) { return C[a] = (a == C[a] ? a : gc(C[a])); }
bool con(int a, int b) {
  if (gc(a) == gc(b)) return 0;
  R[C[a]] += R[gc(b)], C[C[b]] = C[a];
  return --W, 1;
}
int N, a, b, c;
bool lc(int a) {
  while (a) {
    if (a % 10 != 7 && a % 10 != 4) return 0;
    a /= 10;
  }
  return 1;
}
int main(void) {
  scanf("%d", &N), (iota(C, C + N, 0), fill(R, R + N, 1), W = N);
  for (int i(0); i < N - 1; i++) {
    scanf("%d%d%d", &a, &b, &c);
    if (!lc(c)) con(--a, --b);
  }
  long long S = 0;
  for (int i(0); i < N; i++) S += (N - R[gc(i)]) * (N - R[gc(i)] - 1ll);
  printf("%lld\n", S);
  return 0;
}
