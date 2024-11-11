#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int ANS[2333333], *ans = ANS;
int N, A[MAXN];
void Move(int u, int v) {
  A[u] -= A[v];
  A[v] *= 2;
  ans[0] = v;
  ans[1] = u;
  ans += 2;
}
bool cmp(int a, int b) { return A[a] < A[b]; }
int W[MAXN];
void ShandongBlueFly(int a, int b, int c) {
  int Haha = A[b] / A[a];
  while (Haha) {
    if (Haha & 1)
      Move(b, a);
    else
      Move(c, a);
    Haha >>= 1;
  }
}
int main() {
  scanf("%d", &N);
  int i;
  for (i = 1; i <= N; i++) scanf("%d", &A[i]);
  do {
    for (i = 1; i <= N; i++) W[i] = i;
    sort(W + 1, W + N + 1, cmp);
    if (A[W[N - 1]] == 0) {
      printf("-1\n");
      return 0;
    }
    if (A[W[N - 2]] == 0) break;
    ShandongBlueFly(W[N - 2], W[N - 1], W[N]);
  } while (1);
  printf("%d\n", (ans - ANS) / 2);
  for (int* p = ANS; p < ans; p += 2) printf("%d %d\n", p[0], p[1]);
}
