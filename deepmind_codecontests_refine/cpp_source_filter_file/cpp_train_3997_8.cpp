#include <bits/stdc++.h>
using namespace std;
long long N, M, K, A[100005], C[100005], Q[100005];
struct {
  long long l, r, d;
} op[100005];
int main() {
  scanf("%I64%I64d%I64d", &N, &M, &K);
  for (int i = 1; i <= N; i++) scanf("%I64d", A + i);
  for (int i = 1; i <= M; i++)
    scanf("%I64d%I64d%I64d", &op[i].l, &op[i].r, &op[i].d);
  for (int i = 0; i < K; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Q[x]++;
    Q[y + 1]--;
  }
  for (int i = 1; i <= M; i++) Q[i] += Q[i - 1];
  for (int i = 1; i <= M; i++) op[i].d = op[i].d * Q[i];
  for (int i = 1; i <= M; i++) {
    long long x = op[i].l, y = op[i].r, d = op[i].d;
    C[x] += d;
    C[y + 1] -= d;
  }
  for (int i = 1; i <= N; i++) C[i] += C[i - 1];
  for (int i = 1; i <= N; i++) A[i] += C[i];
  for (int i = 1; i < N; i++) printf("%I64d ", A[i]);
  printf("%I64d\n", A[N]);
  scanf("\n");
  return 0;
}
