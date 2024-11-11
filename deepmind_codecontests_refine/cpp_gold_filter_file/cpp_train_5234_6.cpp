#include <bits/stdc++.h>
unsigned long long digit(unsigned long long k) {
  unsigned long long cnt = 0;
  while (k) cnt += k % 10, k /= 10;
  return cnt;
}
unsigned long long work(unsigned long long n, unsigned long long s) {
  if (digit(n) <= s) return 0;
  unsigned long long k = 1, cnt = 0, t = n, ans = 0x7fffffffffffffff;
  while (t) cnt++, t /= 10;
  for (unsigned long long i = 1; i <= cnt; i++) {
    k *= 10;
    if (digit(k - n % k + n) <= s) ans = std::min(ans, k - n % k);
  }
  return ans;
}
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    unsigned long long n, s;
    std::cin >> n >> s;
    std::cout << work(n, s) << "\n";
  }
}
