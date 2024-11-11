#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline long long read() {
  long long o = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > '/' && c < ':') {
    o = o * 10 + c - '0';
    c = getchar();
  }
  return o * f;
}
inline char recd() {
  char o;
  while ((o = getchar()) != 'S' && o != 'L')
    ;
  return o;
}
}  // namespace IO
using namespace IO;
const int SIZE = 1E5 + 7;
int p[SIZE];
int main() {
  int N = read(), K = read();
  for (int pos = 1, w; pos <= N; pos++) w = read(), p[w % K]++;
  long long ans = p[0] - p[0] % 2;
  for (int pos = 1; pos < K; pos++) {
    if (K - pos != pos)
      ans += min(p[pos], p[K - pos]);
    else
      ans += p[pos] - p[pos] % 2;
  }
  printf("%lld\n", ans);
}
