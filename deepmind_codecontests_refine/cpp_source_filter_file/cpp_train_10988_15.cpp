#include <bits/stdc++.h>
using namespace std;
long long T;
int N, M, K;
int A[30];
struct Door {
  int x1, y1, x2, y2;
} D[400];
int main() {
  int i;
  scanf("%I64d", &T);
  for (; T; T /= 6) A[++K] = T % 6;
  N = M = 2;
  D[1] = (Door){1, 2, 2, 2};
  D[2] = (Door){2, 1, 2, 2};
  for (i = K; i; i--) {
    if (A[i] < 3) D[++M] = (Door){N - 1, N + 1, N, N + 1};
    if (!A[i] % 3) D[++M] = (Door){N - 1, N + 2, N, N + 2};
    if (A[i] % 3 < 2) D[++M] = (Door){N + 2, N - 1, N + 2, N};
    D[++M] = (Door){N + 1, N - 1, N + 1, N};
    N += 2;
    if (i < 2) break;
    D[++M] = (Door){N - 2, N, N - 2, N + 1};
    D[++M] = (Door){N - 1, N, N - 1, N + 1};
    D[++M] = (Door){N - 2, N + 2, N - 1, N + 2};
    D[++M] = (Door){N, N - 2, N + 1, N - 2};
    D[++M] = (Door){N, N - 1, N + 1, N - 1};
    D[++M] = (Door){N + 2, N - 2, N + 2, N - 1};
    if (N > 4) {
      D[++M] = (Door){N - 4, N + 1, N - 3, N + 1};
      D[++M] = (Door){N + 1, N - 4, N + 1, N - 3};
    }
  }
  printf("%d %d\n%d\n", N, N, M);
  for (i = 1; i <= M; i++)
    printf("%d %d %d %d\n", D[i].x1, D[i].y1, D[i].x2, D[i].y2);
  return 0;
}
