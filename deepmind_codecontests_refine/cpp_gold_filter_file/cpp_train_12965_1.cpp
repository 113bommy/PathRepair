#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
inline int getgcd(int x, int y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(int x, int y) {
  return (long long)x / getgcd(x, y) * y;
}
inline long long getgcd(long long x, long long y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(long long x, long long y) {
  return x / getgcd(x, y) * y;
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
inline long long power(long long x, long long k, long long p) {
  long long res = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) res = res * x % p;
  return res;
}
const double pi = acos(-1);
inline void judge() { freopen("input.txt", "r", stdin); }
const int lim = 50;
int p[lim + 5], vis[lim + 5], tot;
inline void getp() {
  for (int(i) = (2); (i) <= (lim); (i)++) {
    if (!vis[i]) p[++tot] = i;
    for (int(j) = (1); (j) <= (tot); (j)++) {
      if (i * p[j] > lim) break;
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int flag = 0;
char str[5];
inline bool check(int x) {
  printf("%d\n", x);
  fflush(stdout);
  scanf("%s", str);
  return str[0] == 'y';
}
int main() {
  getp();
  for (int(i) = (1); (i) <= (4); (i)++)
    if (check(p[i])) {
      flag = p[i];
      break;
    }
  if (!flag) {
    printf("prime\n");
    fflush(stdout);
    return 0;
  }
  for (int(i) = (1); (i) <= (tot); (i)++) {
    if (flag * p[i] > 100) break;
    if (check(flag * p[i])) {
      printf("composite\n");
      fflush(stdout);
      return 0;
    }
  }
  printf("prime\n");
  fflush(stdout);
  return 0;
}
