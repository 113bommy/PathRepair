#include <bits/stdc++.h>
using namespace std;
inline void getint(int &x) {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 - '0' + c;
}
int Q1[(1002)], Q2[(1002)], maxk = 0, minmess;
int T[105], n, k;
int main() {
  getint(n), getint(k);
  int i, j, high = 0, low = 10005;
  int hIt, lIt;
  for (i = 1; i <= n; ++i) {
    getint(T[i]);
    if (T[i] > high) high = T[i], hIt = i;
    if (T[i] < low) low = T[i], lIt = i;
  }
  minmess = high - low;
  if (minmess)
    for (j = 1; j <= k; ++j) {
      high = 0, low = 10005;
      for (i = 1; i <= n; ++i) {
        if (T[i] > high) high = T[i], hIt = i;
        if (T[i] < low) low = T[i], lIt = i;
      }
      Q1[j] = hIt, Q2[j] = lIt;
      --T[hIt];
      ++T[lIt];
      high = 0, low = 10005;
      for (i = 1; i <= n; ++i) {
        if (T[i] > high) high = T[i], hIt = i;
        if (T[i] < low) low = T[i], lIt = i;
      }
      if (high - low < minmess) minmess = high - low, maxk = j;
    }
  printf("%d %d\n", minmess, maxk);
  for (i = 1; i <= maxk; ++i) printf("%d %d\n", Q1[i], Q2[i]);
  return 0;
}
