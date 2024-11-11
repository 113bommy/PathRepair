#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, A = 5e5 + 10;
int a[N];
int cnt[A], mobius[A];
void sieve(int lim) {
  mobius[1] = 1;
  vector<int> primes;
  vector<bool> composite(lim + 1);
  for (int i = 2; i <= lim; i++) {
    if (!composite[i]) {
      primes.push_back(i);
      mobius[i] = -1;
    }
    for (int p : primes) {
      if (p * 1LL * i > lim) break;
      composite[p * i] = true;
      if (i % p == 0) break;
      mobius[p * i] = -mobius[i];
    }
  }
}
bool is[A];
vector<int> dv[A];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < A; i++) {
    for (int j = i; j < A; j += i) {
      dv[j].push_back(i);
    }
  }
  sieve(A - 1);
  long long ans = 0;
  while (q--) {
    int first;
    scanf("%d", &first);
    for (int d : dv[a[first]]) {
      ans -= mobius[d] * cnt[d] * 1LL * (cnt[d] - 1) / 2;
      if (!is[first])
        cnt[d]++;
      else
        cnt[d]--;
      ans += mobius[d] * cnt[d] * 1LL * (cnt[d] - 1) / 2;
    }
    is[first] ^= 1;
    printf("ans = %lld\n", ans);
  }
  return 0;
}
