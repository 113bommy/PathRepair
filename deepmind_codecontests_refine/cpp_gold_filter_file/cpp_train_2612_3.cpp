#include <bits/stdc++.h>
using namespace std;
int N, mx = 0;
int il[1000001], pom[1000001], ilprim[1000001];
void check(int n, int m, int a, int b) {
  for (int i = 0; i < 1000001; ++i) ilprim[i] = 0;
  int mxx = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ilprim[abs(i - a) + abs(j - b)]++,
          mxx = max(mxx, abs(i - a) + abs(j - b));
  if (mx != mxx) return;
  for (int i = 0; i <= mx; ++i)
    if (ilprim[i] != il[i]) return;
  printf("%d %d\n%d %d\n", n, m, a, b);
  exit(0);
}
void wczytaj() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    il[a]++;
    mx = max(mx, a);
  }
  if (il[0] != 1) {
    puts("-1");
    exit(0);
  }
  if (N == 1) {
    printf("1 1\n1 1");
    exit(0);
  }
}
int A, B;
int roznica;
void first_two() {
  int i;
  for (i = 1; i <= mx; ++i) {
    if (il[i] > 4 * i) {
      puts("-1");
      exit(0);
    }
    if (il[i] < 4 * i) {
      A = i;
      break;
    }
  }
  roznica = 1;
  for (; i <= mx; ++i) {
    if (il[i] > 4 * i - roznica) {
      puts("-1");
      exit(0);
    }
    if (il[i] < 4 * i - roznica) {
      B = i;
      break;
    }
    roznica += 2;
  }
  roznica += 1;
}
bool add(int I) {
  for (int i = 1; i <= A + I - 1; ++i) {
    pom[I + abs(A - i)]++;
    if (pom[I + abs(A - i)] > il[I + abs(A - i)]) return false;
  }
  for (int i = 1; i <= B + I; ++i) {
    pom[I + abs(B - i)]++;
    if (pom[I + abs(B - i)] > il[I + abs(B - i)]) return false;
  }
  return true;
}
void perp() {
  int C = 0;
  for (int i = 1; i <= A; ++i)
    for (int j = 1; j <= B; ++j) pom[abs(i - A) + abs(j - B)]++;
  for (int I = 1; I <= mx; ++I)
    if (!add(I)) {
      C = I - 1;
      break;
    }
  if (A + C && !(N % (A + C))) check(A + C, N / (A + C), A, B);
  if (B + C && !(N % (B + C))) check(B + C, N / (B + C), B, A);
}
void par() {
  for (int i = 1; i <= mx; ++i) pom[i] = 0;
  int X = A + B - 1, C = 0;
  if (N % X) return;
  for (int i = B; i <= mx; ++i) {
    if (il[i] > 4 * i - roznica) {
      puts("-1");
      exit(0);
    }
    if (il[i] < 4 * i - roznica) {
      C = i;
      break;
    }
    roznica += 4;
  }
  check(X, N / X, A, C);
}
int main() {
  wczytaj();
  first_two();
  perp();
  par();
  puts("-1");
  return 0;
}
