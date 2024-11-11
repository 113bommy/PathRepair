#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long n, m;
inline int read() {
  int x = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -x : x;
}
long long ksm(long long B, long long K, long long A = 1) {
  for (; K; K >>= 1, B = B * B % mod)
    if (K & 1) A = A * B % mod;
  return A;
}
int main() {
  n = read();
  m = read();
  cout << (ksm(2 * n + 2, m) % mod * (1 - m * ksm(n + 1, mod - 2)) % mod +
           mod) %
              mod
       << '\n';
}
