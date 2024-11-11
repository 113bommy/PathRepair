#include <bits/stdc++.h>
using namespace std;
namespace FastIO {
const int L = (1 << 20);
char buf[L], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, L, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  int s = 0, f = 1;
  char t = getchar();
  while ('0' > t || t > '9') {
    if (t == '-') f = -1;
    t = getchar();
  }
  while ('0' <= t && t <= '9') {
    s = (s << 1) + (s << 3) + t - '0';
    t = getchar();
  }
  return s * f;
}
}  // namespace FastIO
using FastIO::read;
const int N = 200005;
int A[N], B[N], rnk[N], n;
void Solve1() {
  if (!rnk[1]) return;
  int pos = rnk[1];
  for (int i = pos + 1; i <= n; i++)
    if (B[i] != B[i - 1] + 1) return;
  int Ord = B[n];
  for (int i = Ord + 1; i <= n; i++) {
    if (rnk[i] <= i - Ord - 1)
      ;
    else
      return;
  }
  cout << n - Ord << '\n';
  exit(0);
}
void Solve2() {
  int b = 0;
  for (int i = 1; i <= n; i++) b = max(rnk[i] - i, b);
  cout << max(rnk[1], b + 1) + n << '\n';
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    A[i] = read();
    if (A[i]) rnk[A[i]] = 0;
  }
  for (int i = 1; i <= n; i++) {
    B[i] = read();
    if (B[i]) rnk[B[i]] = i;
  }
  Solve1();
  Solve2();
  return 0;
}
