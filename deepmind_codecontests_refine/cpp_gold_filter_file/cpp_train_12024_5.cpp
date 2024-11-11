#include <bits/stdc++.h>
using namespace std;
const int Size = 1000010;
int N, A;
int F[Size];
int Ans;
int Max(int A, int B) { return A > B ? A : B; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A);
    ++F[A];
    Ans = Max(F[A], Ans);
    for (int j = 2 * A; j <= Size - 10; j += A) F[j] = Max(F[j], F[A]);
  }
  printf("%d\n", Ans);
}
