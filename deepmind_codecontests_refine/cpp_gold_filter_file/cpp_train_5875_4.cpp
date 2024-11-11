#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char p = getchar();
  while (!(p <= '9' && p >= '0')) p = getchar();
  while (p <= '9' && p >= '0') x *= 10, x += p - 48, p = getchar();
}
inline void read(long long &x) {
  x = 0;
  char p = getchar();
  while (!(p <= '9' && p >= '0')) p = getchar();
  while (p <= '9' && p >= '0') x *= 10ll, x += p - 48, p = getchar();
}
const int N = 1000000;
int n;
int p[1010000];
long long a[1010000], k;
int mp[1010000];
inline void down(int x, long long wei) {
  a[x] -= wei;
  for (x--; x != 1; x /= mp[x]) a[mp[x]] += wei;
}
inline void init() {
  for (int i = (2); i <= (int)N; i++)
    if (!mp[i]) {
      for (int j = (1); j <= (int)N / i; j++)
        if (!mp[j * i]) mp[i * j] = i;
    }
}
inline void BruteForce(long long TOT) {
  for (int tt = (1); tt <= (int)TOT; tt++)
    for (int i = (2); i <= (int)N; i++)
      if (a[i]) down(i, 1);
}
inline void Out() {
  int m = 0;
  for (int i = (2); i <= (int)N; i++)
    if (a[i]) m++;
  printf("%d\n", m);
  for (int i = (2); i <= (int)N; i++)
    if (a[i]) printf("%d %I64d\n", i, a[i]);
}
inline void work() {
  BruteForce(20);
  k -= 20;
  for (int i = (N); i >= (int)2; i--)
    if (a[i]) {
      if (a[i] <= k)
        down(i, a[i]);
      else
        down(i, k);
    }
  Out();
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)n; i++) {
    read(p[i]);
    read(a[p[i]]);
  }
  read(k);
  init();
  if (k <= 20) {
    BruteForce(k);
    Out();
    return 0;
  } else
    work();
  return 0;
}
