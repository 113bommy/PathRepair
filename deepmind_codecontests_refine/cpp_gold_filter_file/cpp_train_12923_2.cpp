#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <typename T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <typename T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % m)
    if (b & 1) ans = (long long)ans * a % m;
  return ans;
}
long long p[1000010];
int r[1000010];
int np;
int prime[1000010], flag[1000010];
void prepare() {
  for (int i = 2; i < 1000010; i++) {
    if (!flag[i]) prime[np++] = i;
    for (int j = 0; j < np && prime[j] * i < 1000010; j++) {
      flag[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  prepare();
  long long n, b;
  scanf("%I64d%I64d", &n, &b);
  int k = 0;
  for (int i = 0; i < np && (long long)prime[i] * prime[i] <= b; i++) {
    if (b % prime[i] == 0) {
      k++;
      p[k] = prime[i];
      while (b % prime[i] == 0) {
        b /= prime[i];
        r[k]++;
      }
    }
  }
  if (b > 1) {
    k++;
    r[k] = 1;
    p[k] = b;
  }
  long long ans = 0x3f3f3f3f3f3f3f3fLL;
  for (int i = 1; i <= k; i++) {
    long long st = p[i];
    long long cnt = 0;
    while (1) {
      cnt += n / st;
      if (st > (n / p[i])) break;
      st *= p[i];
      if (st > n) break;
    }
    smin(ans, cnt / r[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
