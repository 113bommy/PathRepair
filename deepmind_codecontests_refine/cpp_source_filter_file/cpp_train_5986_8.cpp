#include <bits/stdc++.h>
using namespace std;
int N, x[100100], y[100100];
long long bd[100100], ar[100100];
long long Bd[100100], Ar[100100];
long long absx(long long x) {
  if (x < 0) return -x;
  return x;
}
int absx(int x) {
  if (x < 0) return -x;
  return x;
}
inline long long area(int a, int b) {
  b = b % N;
  long long ret = Ar[b] - Ar[a];
  if (b < a) {
    ret += Ar[N];
  }
  int k = b % N, l = a % N;
  ret += 1LL * x[k] * y[l] - 1LL * x[l] * y[k];
  return absx(ret);
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long border(int a, int b) {
  b = b % N;
  long long ret = Bd[b] - Bd[a];
  if (b < a) {
    ret += Bd[N];
  }
  int k = b % N, l = a % N;
  ret += gcd(absx(x[k] - x[l]), absx(y[k] - y[l]));
  return absx(ret);
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i < N; ++i) {
    int j = (i + 1) % N;
    bd[i] = gcd(absx(x[i] - x[j]), absx(y[i] - y[j]));
  }
  for (int i = 0; i < N; ++i) {
    int j = (i + 1) % N;
    ar[i] = 1LL * x[i] * y[j] - 1LL * x[j] * y[i];
  }
  for (int i = 1; i <= N; ++i) {
    Bd[i] = Bd[i - 1] + bd[i - 1];
    Ar[i] = Ar[i - 1] + ar[i - 1];
  }
  long long A = area(0, N - 1);
  long long B = border(0, N - 1);
  long long I = (A - B + 2) / 2;
  long double rez = I * 1.0;
  for (int i = 0; i < N; ++i) {
    for (int k = 2; k < N - 1 && k <= 60; ++k) {
      int j = (i + k) % N;
      long long B = border(i, i + k);
      long double p = 1.0 * (1LL << (k + 1));
      if (N <= 60) {
        long long z = 1 + N + 1LL * N * (N - 1) / 2;
        long double p2 = 1.0 * z;
        long long a = (1 << (N - k - 1));
        p2 /= a;
        p -= p2;
      }
      p = 1.0 / p;
      if (N <= 60) {
        long long z = (1LL << N) - 1 - N - 1LL * N * (N - 1) / 2;
        p -= 1.0 / z;
      }
      long long A = area(i, i + k);
      long long I = (A - B + 2) / 2;
      int z = gcd(absx(x[i] - x[j]), absx(y[i] - y[j])) - 1;
      rez -= p * 1.0 * (I + z);
    }
  }
  cout << setprecision(10) << rez;
  return 0;
}
