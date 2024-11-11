#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009;
long long tpot(int e) {
  if (e == 0) return 1;
  int sq = 0;
  while (e && e % 2 == 0) {
    e /= 2;
    sq++;
  }
  if (sq == 0) {
    return (2 * tpot(e - 1)) % MOD;
  }
  long long tpl = tpot(e);
  for (int i = 0; i < sq; i++) tpl = (tpl * tpl) % MOD;
  return tpl;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long nq = (n - m) * k, np = nq - (n - m);
  if (nq >= n)
    cout << (np % MOD) << '\n';
  else {
    long long rem = n - nq;
    long long e = rem / k, add = rem % k;
    cout << ((MOD + (k * (tpot(e + 1) - 2) + add + np)) % MOD) << '\n';
  }
  return 0;
}
