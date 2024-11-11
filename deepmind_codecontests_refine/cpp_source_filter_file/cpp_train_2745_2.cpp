#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:255000000")
bool firstout = 1;
template <class T>
T &minn(T &a, T b) {
  if (b < a) a = b;
  return a;
}
template <class T>
T &maxx(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int &madd(int &a, int b) {
  a += b;
  if (a >= 1000000009) a -= 1000000009;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000009;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000009; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int n, m, q;
int A[2 * 101234];
int **P;
long long D[101234];
int main() {
  int i, j, k;
  char c;
  int a, d;
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(q)) > 0;
       ++ts) {
    scanf(
        "%"
        "d",
        &(n));
    scanf(
        "%"
        "d",
        &(m));
    long long t;
    scanf(
        "%"
        "I64d",
        &(t));
    t *= n;
    P = new int *[2 * n + 1];
    for (i = (0); i < (2 * n + 1); ++i) P[i] = new int[m];
    for (; q--;) {
      for (i = (0); i < (n); ++i)
        scanf(
            "%"
            "d",
            &(A[i])),
            --A[i], A[n + i] = A[i];
      for (j = (0); j < (m); ++j) P[2 * n][j] = 1012345678;
      for (i = (2 * n) - 1; i >= (0); --i) {
        for (j = (0); j < (m); ++j) P[i][j] = P[i + 1][j] + 1;
        P[i][A[i]] = 1;
      }
      for (i = (0); i < (m + 1); ++i) D[i] = 0;
      for (i = (0); i < (1012345678); ++i) {
        if (D[m - 1] >= t || m - 1 < i) break;
        for (j = (m)-1; j >= (i); --j)
          if (P[D[j] % n][j] >= 1012345678)
            D[j + 1] = t;
          else
            D[j + 1] = D[j] + P[D[j] % n][j];
        for (j = (i + 2); j < (m + 1); ++j) minn(D[j], D[j - 1]);
        if (D[m] >= t) break;
      }
      int res = i;
      printf(
          "%"
          "d",
          (res));
      printf("\n"), firstout = 1;
    }
  }
  return 0;
}
