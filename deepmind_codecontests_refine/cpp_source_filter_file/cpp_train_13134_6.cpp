#include <bits/stdc++.h>
using namespace std;
const int maxn = 300050;
int n;
long long p, k;
long long A[maxn];
unordered_map<long long, int> mp;
int main() {
  scanf("%d%lld%lld", &n, &p, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &A[i]);
    long long x = A[i] * (A[i] * A[i] * A[i] % p - k + p) % p;
    mp[x]++;
  }
  long long ans = 0;
  for (auto x : mp) {
    ans += x.second * (x.second - 1) / 2;
  }
  printf("%lld", ans);
  return 0;
}
