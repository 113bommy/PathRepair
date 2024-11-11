#include <bits/stdc++.h>
int main() {
  long long n, m;
  scanf("%I64d %I64d", &n, &m);
  char buff[200000 + 1];
  scanf("%200000s", buff);
  std::string a(buff);
  scanf("%200000s", buff);
  std::string b(buff);
  const long long M = 998244353;
  std::vector<long long> pow2(n);
  pow2[0] = 1;
  for (int i = 1; i < n; i++) {
    pow2[i] = pow2[i - 1] * 2 % M;
  }
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  long long ans = 0;
  long long c1 = 0;
  for (int i = m - 1; i >= 0; i--) {
    c1 += b[i] == '1';
    if (i < n && a[i] == '1') {
      ans = (ans + c1 * pow2[i]) % M;
    }
  }
  printf("%I64d", ans);
  return 0;
}
