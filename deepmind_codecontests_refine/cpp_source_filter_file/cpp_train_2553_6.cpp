#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int mul(int a, int b) { return (long long)a * b % MOD; }
int power(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
int inverseMod(int a) { return power(a, MOD - 2); }
const int N = 1e5 + 5;
int fact[N];
int invFact[N];
int ncr(int n, int r) {
  if (n < r) return 0;
  return mul(fact[n], mul(invFact[r], invFact[n - r]));
}
const int M = 1e6 + 1;
int phi[M];
void sieve() {
  for (int i = 1; i < M; i++) phi[i] = i;
  for (int i = 2; i < M; i++) {
    if (phi[i] == i) {
      for (int j = i; j < M; j += i) phi[j] = (phi[j] / i) * (i - 1);
    }
  }
}
int cnt[M];
int cnt2[M];
int main() {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    invFact[i] = inverseMod(fact[i]);
  }
  sieve();
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    cnt[t]++;
  }
  for (int i = 1; i < M; i++)
    for (int j = i; j < M; j += i) cnt2[i] += cnt[j];
  int ans = 0;
  for (int i = 1; i < M; i++) {
    add(ans, mul(ncr(cnt2[i], k), phi[i]));
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i * i <= t; i++) {
      if (t % i == 0) {
        add(ans, -mul(ncr(cnt2[i], k), phi[i]));
        cnt2[i]++;
        add(ans, mul(ncr(cnt2[i], k), phi[i]));
        if (i * i != t) {
          add(ans, -mul(ncr(cnt2[t / i], k), phi[t / i]));
          cnt2[t / i]++;
          add(ans, mul(ncr(cnt2[t / i], k), phi[t / i]));
        }
      }
    }
    printf("%d\n", ans);
  }
}
