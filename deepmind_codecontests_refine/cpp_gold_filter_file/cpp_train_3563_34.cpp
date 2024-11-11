#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x);
template <typename T>
void write(T x);
template <typename T>
void writesp(T x);
template <typename T>
void writeln(T x);
const long long N = 81;
long long n, k;
long long edge[N][N];
bool col[N];
long long Cnt;
long long f[N][11], ans;
int main() {
  srand(time(0));
  read(n);
  read(k);
  for (register long long i = 1; i <= n; i++) {
    for (register long long j = 1; j <= n; j++) read(edge[i][j]);
  }
  Cnt = 5000, ans = 0x3f3f3f3f3f3f3f3f;
  while (Cnt--) {
    for (register long long i = 1; i <= n; i++) col[i] = rand() & 1;
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (register long long now = 1; now <= k; now++) {
      for (register long long i = 1; i <= n; i++) {
        for (register long long j = 1; j <= n; j++) {
          if (col[i] != col[j])
            f[i][now] = min(f[i][now], f[j][now - 1] + edge[i][j]);
        }
      }
    }
    ans = min(ans, f[1][k]);
  }
  writeln(ans);
}
template <typename T>
void read(T &x) {
  char wn = getchar();
  long long t = 1;
  x = 0;
  while (wn < '0' || wn > '9') {
    if (wn == '-') t = -1;
    wn = getchar();
  }
  while (wn >= '0' && wn <= '9') {
    x = x * 10 + wn - '0';
    wn = getchar();
  }
  x *= t;
}
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x <= 9) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <typename T>
void writesp(T x) {
  write(x);
  putchar(' ');
}
