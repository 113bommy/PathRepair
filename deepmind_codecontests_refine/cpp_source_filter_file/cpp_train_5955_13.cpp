#include <bits/stdc++.h>
namespace my_std {
using namespace std;
template <typename _Tp>
inline _Tp read() {
  register _Tp ans = 0, f = 1;
  register char c = getchar();
  while (!isdigit(c)) f ^= (c == '-'), c = getchar();
  for (; isdigit(c); c = getchar()) ans = (ans << 1) + (ans << 3) + (c ^ 48);
  return f ? ans : -ans;
}
}  // namespace my_std
using namespace my_std;
inline long long sum1(const long long &p, const long long &k) {
  return (p * 2 + k - 1) * k / 2;
}
inline long long find(const long long &B, const long long &K) {
  if (!B) return (K & 1) ? (K + 1) / 2 * K : K / 2 * (K + 1);
  const long long x = find(B / K, K), c = B % K;
  long long res = (B / K) * (K * K + 1) + c * K + 1;
  if (res + K <= x)
    return sum1(res, K);
  else
    return sum1(res, K) + min(res - K - x, K);
}
inline void work() {
  const long long n = read<long long>(), K = read<long long>();
  long long B = (n - 1) / (K * K + 1), x = find(B, K);
  if (x == n) return printf("%lld\n", (B + 1) * (K + 1)), void();
  long long p = n - B - 1 + (n < x);
  long long t = (n - 1) % (K * K + 1) + 1;
  printf("%lld\n", p + B * K + (t - 1 - (n >= x)) / K);
}
int main() {
  int esac = read<int>();
  while (esac--) work();
}
