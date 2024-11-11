#include <bits/stdc++.h>
using namespace std;
struct {
  uint32_t A, B, C, D;
} coef;
inline uint32_t calcF(uint32_t p) {
  return coef.D + p * (coef.C + p * (coef.B + p * coef.A));
}
inline uint32_t calcVal(uint32_t n, uint32_t p) {
  uint32_t tmp = 0;
  while ((n /= p) > 0) {
    tmp += n;
  }
  tmp *= calcF(p);
  return tmp;
}
uint32_t ans;
bitset<50000000> A, B;
uint32_t n;
inline void processP(uint32_t p) {
  ans += calcVal(n, p);
  if (p > 20000) return;
  for (uint32_t x = p; x <= n; x += p) {
    if (x % 6 == 5) {
      A[x / 6] = 1;
    } else if (x % 6 == 1) {
      B[x / 6 - 1] = 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> coef.A >> coef.B >> coef.C >> coef.D;
  if (2 <= n) processP(2);
  if (3 <= n) processP(3);
  for (uint32_t p = 6; p - 1 <= n; p += 6) {
    if (A[p / 6 - 1] == 0) processP(p - 1);
    if (p + 1 <= n && B[p / 6] == 0) processP(p + 1);
  }
  cout << ans << "\n";
}
