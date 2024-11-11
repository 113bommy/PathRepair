#include <bits/stdc++.h>
int N, A[100005], X, P;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < N; i++)
    if (A[i] == i)
      X++;
    else {
      if (A[A[i]] == i)
        P = 2;
      else
        P = P < 2 ? 1 : 0;
    }
  printf("%d", X + P);
}
