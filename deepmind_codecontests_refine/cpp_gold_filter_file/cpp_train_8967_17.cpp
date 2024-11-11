#include <bits/stdc++.h>
using namespace std;
const long long P = 1e6 + 3;
long long a[15][15], b[15];
int ask(int i) {
  printf("? %d\n", i);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
long long inv(long long bs) {
  long long ans = 1, x = P - 2;
  while (x) {
    if (x & 1) ans = ans * bs % P;
    bs = bs * bs % P;
    x >>= 1;
  }
  return ans;
}
void gao() {
  for (int i = 0; i <= 10; i++) {
    for (int j = i + 1; j <= 10; j++) {
      long long rate = a[j][i] * inv(a[i][i]) % P;
      for (int k = i; k <= 11; k++) {
        a[j][k] -= a[i][k] * rate % P;
        a[j][k] += P;
        a[j][k] %= P;
      }
    }
  }
  for (int i = 10; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      long long rate = a[j][i] * inv(a[i][i]) % P;
      a[j][11] -= a[i][11] * rate % P;
      a[j][11] += P;
      a[j][11] %= P;
    }
    a[i][i] = a[i][11] * inv(a[i][i]) % P;
  }
}
int chk(long long x) {
  b[0] = 1;
  for (int i = 1; i <= 10; i++) b[i] = b[i - 1] * x % P;
  long long sum = 0;
  for (int i = 0; i <= 10; i++) {
    sum += b[i] * a[i][i] % P;
    sum %= P;
  }
  return sum == 0;
}
int main() {
  for (int i = 0; i <= 10; i++) {
    a[i][11] = ask(i);
    long long p = 1;
    for (int j = 0; j <= 10; j++) {
      a[i][j] = p;
      p = p * i % P;
    }
  }
  gao();
  for (int i = 0; i < P; i++) {
    if (chk(i)) {
      printf("! %d\n", i);
      fflush(stdout);
      return 0;
    }
  }
  printf("! -1\n");
  fflush(stdout);
}
