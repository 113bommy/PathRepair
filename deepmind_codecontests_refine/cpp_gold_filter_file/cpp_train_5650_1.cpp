#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int T, n;
int a[MAXN];
inline int read() {
  char ch = getchar();
  int sum = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
  return sum;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    int mxa = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      mxa = max(mxa, a[i]);
      sum += a[i];
    }
    if (mxa > sum / 2 || sum & 1)
      printf("T\n");
    else
      printf("HL\n");
  }
  return 0;
}
