#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - 48;
    s = getchar();
  }
  return f * x;
}
const int N = 1e6 + 5;
int a[N], b[N], ch[N][2], size[N];
long long val[N];
int main() {
  int n = read();
  long long k = read();
  a[1] = b[1] = 1;
  for (int i = 2; i <= n; i++) {
    int fa = read();
    long long v = read();
    val[i] = val[fa] ^ v;
    a[i] = b[i] = 1;
  }
  long long ans = 0;
  for (int i = 61; i >= 0; i--) {
    int cnt = 0;
    long long sum = 0;
    for (int j = 1; j <= n; j++) ch[j][0] = ch[j][1] = size[j] = 0;
    for (int j = 1; j <= n; j++) {
      int &p = ch[a[j]][(val[j] >> i) & 1];
      if (!p) p = ++cnt;
      size[a[j] = p]++;
    }
    for (int j = 1; j <= n; j++) sum += size[ch[b[j]][(val[j] >> i) & 1]];
    int op = 0;
    if (sum < k) k -= sum, op = 1, ans |= (1ll << i);
    for (int j = 1; j <= n; j++) b[j] = ch[b[j]][((val[j] >> i) & 1) ^ op];
  }
  printf("%lld\n", ans);
  return 0;
}
