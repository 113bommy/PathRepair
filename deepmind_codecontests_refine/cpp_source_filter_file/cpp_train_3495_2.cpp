#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
int mindiv[1000001], prime[1000001];
unsigned char bv[1000001];
int f[1000001][20];
void print(int num) {
  if (num >= 10) print(num / 10);
  putchar(num % 10 + '0');
}
int main() {
  register int ptr = 0;
  for (register int i = 2; i <= 1000000; i++) {
    if (!bv[i]) {
      mindiv[i] = i;
      prime[ptr] = i;
      ptr++;
    }
    for (register int j = 0; j < ptr; j++) {
      int cjr = i * prime[j];
      if (cjr > 1000000) break;
      mindiv[cjr] = prime[j];
      bv[cjr] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  f[0][0] = 1;
  for (register int i = 1; i <= 19; i++) f[0][i] = 2;
  for (register int i = 1; i <= 1000000; i++) {
    long long sums = 0;
    for (register int j = 0; j <= 19; j++) {
      sums = (sums + f[i - 1][j]) % 10000000007;
      f[i][j] = sums;
    }
  }
  int t = get();
  while (t) {
    t--;
    int r = get(), n = get();
    long long ans = 1;
    while (n != 1) {
      int pri = mindiv[n];
      int t = 0;
      while (mindiv[n] == pri) {
        t++;
        n /= mindiv[n];
      }
      ans = (ans * f[r][t]) % 10000000007;
    }
    print(ans);
    putchar('\n');
  }
  return (0);
}
