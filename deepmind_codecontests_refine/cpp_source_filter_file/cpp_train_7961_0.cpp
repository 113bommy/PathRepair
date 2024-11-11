#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000100;
bool p[MAX];
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
int main() {
  for (int i = (2); i < (MAX); ++i) p[i] = true;
  for (int i = 2; i * i < MAX; ++i)
    if (p[i])
      for (int j = i * i; j < MAX; j += i) p[j] = false;
  long long A;
  scanf("%lld", &A);
  unordered_map<long long, long long> f, g;
  f[A] = 1;
  for (int i = (0); i < (MAX); ++i)
    if (p[i]) {
      g.clear();
      for (long long n = i; n < A; n *= i) {
        if (A % (n + 1)) continue;
        for (auto it : f)
          if (it.first % (n + 1) == 0) g[it.first / (n + 1)] += it.second;
      }
      for (auto it : g) f[it.first] += it.second;
    }
  long long ans = f[1];
  for (auto it : f)
    if (it.first > MAX && is_prime(it.first)) ans += it.second;
  printf("%lld\n", f[1]);
  return 0;
}
