#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const long long N = 300010;
struct edge {
  long long v, w, nx;
} e[N << 1];
long long hd[N], cnt;
void add(long long u, long long v, long long w) {
  e[++cnt] = (edge){v, w, hd[u]};
  hd[u] = cnt;
}
long long qp(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
long long t, n, m;
long long a, b, c;
long long pr[25] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int main() {
  int tt = rd();
  while (tt--) {
    n = rd();
    c = 1;
    n--;
    if (n & 1) {
      printf("2 %lld 1\n", n - 2);
      continue;
    } else {
      for (long long i = 1; i <= 13; i++) {
        if (n % pr[i] == 0) continue;
        printf("%lld %lld %lld\n", pr[i], n - pr[i], 1);
        break;
      }
    }
  }
  return 0;
}
