#include <bits/stdc++.h>
using namespace std;
const long long lim = 10000;
template <typename T>
inline T read() {
  register T sum = 0;
  register char cc = getchar();
  int sym = 1;
  while (cc != '-' && (cc > '9' || cc < '0')) cc = getchar();
  if (cc == '-') sym = -1, cc = getchar();
  sum = sum * 10 + cc - '0';
  cc = getchar();
  while (cc >= '0' && cc <= '9') sum = sum * 10 + cc - '0', cc = getchar();
  return sym * sum;
}
template <typename T>
inline T read(T& a) {
  a = read<T>();
  return a;
}
template <typename T, typename... Others>
inline void read(T& a, Others&... b) {
  a = read(a);
  read(b...);
}
long long f[10010][5], buck[10010];
int main() {
  for (int j = 1; j <= 4; j++)
    for (int i = 1; i <= lim; i++) {
      long long pos = i;
      f[i][j] = f[i][j - 1];
      pos = min(i + f[i][j - 1] + 1, lim);
      for (int k = 1; k <= i; k++) {
        if (pos == lim) {
          f[i][j] += (f[pos][j - 1] + 1) * (i - k + 1);
          break;
        }
        f[i][j] += f[pos][j - 1] + 1;
        pos = min(pos + f[i][j - 1] + 1, lim);
      }
    }
  long long pos = 1;
  for (int i = 4; i >= 0; i--) {
    long long t = pos;
    buck[0] = t - 1;
    int cnt = 0;
    for (int j = 1; j <= min(pos, lim); j++) {
      t += f[min(t, lim)][i];
      buck[++cnt] = t;
      t += 1;
    }
    printf("%d ", cnt);
    for (int j = 1; j <= cnt; j++) printf("%lld ", buck[j]);
    putchar('\n');
    fflush(stdout);
    int op;
    read(op);
    if (op < 0) return 0;
    pos = buck[op] + 1;
  }
  return 0;
}
