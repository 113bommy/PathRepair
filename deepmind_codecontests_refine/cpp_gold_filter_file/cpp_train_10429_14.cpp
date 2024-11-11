#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  char c = getchar();
  int f = 0;
  for (; c < '0' || c > '9'; f |= c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int N = 2e6 + 233;
int phi[N], np[N], p[N], p_cnt = 0, n, K;
inline void prepare(int n) {
  phi[1] = 1;
  np[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++p_cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= p_cnt && p[j] * i <= n; j++) {
      np[p[j] * i] = true;
      if (i % p[j] == 0)
        phi[i * p[j]] = phi[i] * p[j];
      else
        phi[i * p[j]] = phi[i] * phi[p[j]];
      if (i % p[j] == 0) break;
    }
  }
}
int main(void) {
  read(n);
  read(K);
  if (K == 1) return cout << 3 << "\n", 0;
  prepare(n);
  sort(phi + 3, phi + n + 1);
  long long ans = 2;
  for (register int t = 1; t <= (K); t++) ans += phi[t + 2];
  cout << ans << "\n";
}
