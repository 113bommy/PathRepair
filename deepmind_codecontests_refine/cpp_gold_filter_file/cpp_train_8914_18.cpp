#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y) {
  x %= 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i) (res *= i) %= 1000000007;
  return res;
}
bool isprime(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i <= n - 1; ++i) cin >> v[i];
  vector<int> ans(n, -1);
  map<int, int> mp;
  for (int i = 0; i <= n - 1; ++i) {
    mp[v[i]] = i;
  }
  map<int, int> mp1;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    if (it == mp.begin()) {
      mp1[it->first] = mp[it->first];
      continue;
    }
    int ind = it->second, val = it->first;
    mp1[val] = max(ind, (*--mp1.end()).second);
  }
  for (int i = 0; i <= n - 1; ++i) {
    auto it = mp1.lower_bound(v[i]);
    if (it == mp1.begin()) {
      ans[i] = -1;
      continue;
    }
    --it;
    ans[i] = max(-1, mp1[it->first] - i - 1);
  }
  for (auto c : ans) cout << c << ' ';
  return 0;
}
