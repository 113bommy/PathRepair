#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - 48;
    c = getchar();
  }
  return x * f;
}
const int N = 1e6 + 7;
long long val[N];
int A[N], B[N], siz[N], ch[N][2];
int main() {
  long long n = read(), k = read();
  A[1] = B[1] = 1;
  for (int i = 2; i <= n; i++) {
    long long fa = read(), w = read();
    val[i] = val[fa] ^ w;
    A[i] = B[i] = 1;
  }
  long long ans = 0;
  for (int i = 61; i >= 0; i--) {
    long long cnt = 0, sum = 0;
    for (int j = 1; j <= n; j++) ch[j][0] = ch[j][1] = siz[j] = 0;
    for (int j = 1; j <= n; j++) {
      int &p = ch[A[j]][(val[j] >> i) & 1];
      if (!p) p = ++cnt;
      siz[A[j] = p]++;
    }
    for (int j = 1; j <= n; j++) {
      sum += siz[ch[B[j]][val[j] >> i & 1]];
    }
    int op = 0;
    if (sum < k) k -= sum, op = 1, ans |= 1ll << i;
    for (int j = 1; j <= n; j++) {
      B[j] = ch[B[j]][((val[j] >> i) & 1) ^ op];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
