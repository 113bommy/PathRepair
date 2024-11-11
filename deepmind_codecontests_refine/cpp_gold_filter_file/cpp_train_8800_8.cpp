#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long f[5000005];
long long fact(long long x) {
  if (x == 0) return f[x] = 1;
  if (f[x] != 0) return f[x];
  return f[x] = (x * fact(x - 1)) % MOD;
}
long long power(long long x, int k) {
  if (k == 0) return 1;
  long long ret = power(x, k / 2) % MOD;
  if (k % 2) return (((ret * ret) % MOD) * x) % MOD;
  return (ret * ret) % MOD;
}
long long comp(int a, int b, int c) {
  long long ret = fact(a) * power(fact(b), MOD - 2);
  ret %= MOD;
  ret *= power(fact(c), MOD - 2);
  ret %= MOD;
  return ret;
}
long long cont[200005];
int main() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  map<int, int> mp1, mp2;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    s.insert(a);
    s.insert(b);
    mp1[a]++;
    mp2[b]++;
  }
  vector<int> p(s.begin(), s.end());
  int points = int(p.size());
  p.push_back(p[points - 1] + 1);
  int seg = 0;
  for (int i = 0; i < points; i++) {
    seg += mp1[p[i]];
    seg -= mp2[p[i]];
    cont[seg + mp2[p[i]]]++;
    cont[seg] += (p[i + 1] - p[i] - 1);
  }
  long long ans = 0;
  for (int i = k; i <= n; i++) {
    ans += (cont[i] * comp(i, k, i - k));
    ans %= MOD;
  }
  cout << ans % MOD << endl;
}
