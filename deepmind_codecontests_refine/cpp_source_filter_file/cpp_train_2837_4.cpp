#include <bits/stdc++.h>
using namespace std;
const long long N = 50;
long long n, m, hang[N], lie[N], sum1, sum2, sum;
inline long long read() {
  long long x = 0, tmp = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return tmp * x;
}
inline void clean() {
  memset(hang, 0, sizeof(hang));
  memset(lie, 0, sizeof(lie));
  sum1 = sum2 = 0;
}
int main() {
  for (long long T = read(); T; T--) {
    clean();
    n = read();
    m = read();
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        long long x = read();
        if (x) hang[i] = lie[j] = 1;
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (hang[i] == 0) sum1++;
    }
    for (long long i = 1; i <= m; i++) {
      if (lie[i] == 0) sum2++;
    }
    sum = min(sum1, sum2);
    if (sum & 1)
      printf("Ashish\n");
    else
      printf("Vivek\n");
  }
  return 0;
}
