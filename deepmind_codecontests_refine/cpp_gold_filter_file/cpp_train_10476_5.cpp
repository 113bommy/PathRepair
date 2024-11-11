#include <bits/stdc++.h>
using namespace std;
int scanst(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
template <typename T>
bool scan(T &n) {
  n = 0;
  bool got = false;
  bool negative = false;
  char c = getchar();
  if (c == EOF) return false;
  while (c<'0' | c> '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    got = true;
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return got;
}
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M) {
  return BigMod(A, M - 2, M);
}
int gcdr(int a, int b) {
  if (a == 0) return b;
  return gcdr(b % a, a);
}
int main() {
  int n, m, p, q;
  char arr[200];
  while (scanf("%s", &arr) != EOF) {
    vector<int> G[10];
    int i, sz = strlen(arr);
    for (i = 0; i <= sz - 1; i++) {
      if (arr[i] == 'Q')
        G[0].push_back(i);
      else if (arr[i] == 'A')
        G[1].push_back(i);
    }
    int j, k, szQ = G[0].size(), szA = G[1].size(), ans = 0;
    for (i = 0; i <= szQ - 1; i++) {
      int fQ = G[0][i];
      for (j = 0; j <= szA - 1; j++) {
        int A = G[1][j];
        if (A > fQ)
          for (k = i + 1; k <= szQ - 1; k++) {
            int sQ = G[0][k];
            if (sQ > A) ans++;
          }
        else
          continue;
      }
    }
    printf("%d\n", ans);
  }
}
