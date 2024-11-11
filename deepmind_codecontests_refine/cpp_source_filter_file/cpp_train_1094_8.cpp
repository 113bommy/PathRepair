#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
long long S[(200002)];
int N, A[(200002)];
struct STOP {
  clock_t S;
  void ini() { S = clock(); }
  bool ok(long double Z) {
    return (clock() - S) / (long double)CLOCKS_PER_SEC < Z;
  };
} F;
int I = 1, J = 1, U = 1, V = 1, u = 1, v = 1, g, W;
long double C, B = 1e18;
bool ok() { return J > 0 && I >= J && I + J < N; }
long double fit() {
  if (!ok()) return 1e18;
  long double a = (S[I] - (I - J ? S[I - J - 1] : 0)) +
                  (S[N - 1] - (N - J ? S[N - J - 1] : 0));
  return A[I] - a / (J * 2 | 1);
}
void nxt() {
  I = U, J = V;
  if (rand() & 1) {
    if (rand() & 1)
      --J;
    else
      ++J;
  } else if (rand() & 1) {
    if (rand() & 1)
      ++I;
    else
      --I;
  }
  if (W++ > 20 && !(rand() % 7)) {
    if (!(rand() & 1))
      J -= N / 10;
    else
      J += N / 10;
  }
}
void solANL() {
  long double T = 1e5, d, c = .999994, a = 1e-5;
  C = fit(), F.ini();
GOW:
  while (T > a) {
    nxt();
    d = fit() - C;
    if (d < 0 || exp(-d / T) > (rand() % (1000) * 1. / (1000))) {
      U = I, V = J, C = d + C;
      if (C < B) B = C, u = U, v = V;
    }
    T *= c;
  }
  if (!F.ok(2.6)) return;
  T = 1e5, W = 0;
  if (!g++)
    V = U = 1;
  else if (g++ == 1)
    V = (rand() << 16 | rand()) % N / 2 + 1,
    U = (rand() << 16 | rand()) % (N - 2 * V + 1) + V;
  goto GOW;
}
int main(void) {
  srand(time(0));
  scanf("%d", &N), ga(N, A), sort(A, A + N), *S = *A;
  if (N < 3) return printf("1\n%d\n", *A), 0;
  for (int k(1); k < N; k++) S[k] = A[k] + S[k - 1];
  V = N / 2 - 1, U = N / 2, solANL();
  I = u, J = v;
  if (fit() > -(1e-10)) return printf("1\n%d\n", *A), 0;
  printf("%d\n", v * 2 | 1);
  for (int i(0); i < v; i++) printf("%d ", A[u - i - 1]);
  for (int i(0); i < v; i++) printf("%d ", A[N - i - 1]);
  printf("%d\n", A[u]);
  return 0;
}
