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
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000007; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int n, m, q, p;
char S[111], SS[111];
int D[111][111];
long long A[111], AA[111];
int AI[111], AAI[111];
long long B[111], BB[111];
int main() {
  int i, j, k;
  char c;
  int a, d;
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(p)) > 0;
       ++ts) {
    scanf(
        "%"
        "d",
        &(q));
    scanf(
        "%"
        "s",
        &(S));
    scanf(
        "%"
        "s",
        &(SS));
    n = strlen(S);
    m = strlen(SS);
    for (i = (0); i < (m); ++i) {
      for (j = (0); j < (n); ++j)
        if (S[j] == SS[i]) break;
      if (j == n) break;
    }
    if (i < m)
      printf(
          "%"
          "d",
          (0));
    else {
      for (i = (0); i < (n); ++i)
        for (j = (0); j < (m); ++j) {
          for (k = i; S[k % n] != SS[j]; ++k)
            ;
          D[i][j] = k - i + 1;
        }
      for (i = (0); i < (n); ++i) {
        long long res = 0;
        j = 0;
        for (k = (0); k < (m); ++k) {
          res += D[j][k];
          j += D[j][k];
          if (j >= n) j -= n;
        }
        A[i] = res;
        AI[i] = j;
      }
      for (i = (0); i < (n); ++i) {
        for (j = (0); j < (n); ++j) BB[j] = B[j] = -1;
        j = i;
        long long res = 0;
        for (k = (0); k < (q); ++k) {
          if (B[j] >= 0) break;
          B[j] = k;
          BB[j] = res;
          res += A[j];
          j = AI[j];
        }
        if (k == q) {
          AA[i] = res;
          AAI[i] = j;
          continue;
        }
        long long l = k - B[j];
        long long r = res - BB[j];
        long long t = (q - k) / l;
        res += r * t;
        k += l * t;
        for (k = (k); k < (q); ++k) {
          res += A[j];
          j = AI[j];
        }
        AA[i] = res;
        AAI[i] = j;
        continue;
      }
      p *= n;
      for (j = (0); j < (n); ++j) BB[j] = B[j] = -1;
      j = 0;
      long long res = 0;
      for (k = 0; res + AA[j] <= p; ++k) {
        if (B[j] >= 0) break;
        B[j] = k;
        BB[j] = res;
        res += AA[j];
        j = AAI[j];
      }
      if (res + AA[j] <= p) {
        long long l = k - B[j];
        long long r = res - BB[j];
        long long t = (p - res) / r;
        res += r * t;
        k += l * t;
        for (; res + AA[j] <= p; ++k) {
          res += AA[j];
          j = AAI[j];
        }
      }
      printf(
          "%"
          "d",
          (k));
    }
    printf("\n"), firstout = 1;
  }
  return 0;
}
