#include <bits/stdc++.h>
using namespace std;
long long nCr[40][40];
void eval_nCr() {
  for (long long n = 0; n < 40; n++)
    for (long long r = 0; r <= n; r++)
      nCr[n][r] = r == 0 ? 1 : nCr[n - 1][r] + nCr[n - 1][r - 1];
}
multiset<long long> encode(long long n) {
  multiset<long long> encoding = multiset<long long>();
  for (long long i = 1; n; i++) {
    encoding.insert(n % i);
    n /= i;
  }
  return encoding;
}
long long duplicates(multiset<long long> code) {
  long long ans = 1;
  while (code.size()) {
    long long e = *code.rbegin();
    ans *= nCr[code.size() - e][code.count(e)];
    code.erase(e);
  }
  return ans;
}
void test() {
  long long k;
  scanf("%lli", &k);
  multiset<long long> code = encode(k);
  long long ans = duplicates(code);
  code.erase(code.find(0));
  ans -= duplicates(code);
  printf("%lli\n", ans - 1);
}
signed main() {
  eval_nCr();
  long long q;
  cin >> q;
  while (q--) test();
}
